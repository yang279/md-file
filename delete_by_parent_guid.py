import json


def _guid_key(guid: dict) -> tuple:
    return (guid.get("sessionID"), guid.get("localID"))


def delete_by_guid(data: dict, target_guid: dict) -> dict:
    """
    1. 删除 guid == target_guid 的节点
    2. 删除 parentIndex.guid == target_guid 的子节点
    3. 循环清理孤儿节点（父节点不存在且非自引用根节点）
    """
    target_key = _guid_key(target_guid)
    nodes = data["node"]

    # 删除目标节点本身及其直接子节点
    nodes = [
        item for item in nodes
        if _guid_key(item.get("guid", {})) != target_key
        and _guid_key(item.get("parentIndex", {}).get("guid", {})) != target_key
    ]

    # 循环清理孤儿节点
    while True:
        existing_keys = {_guid_key(item.get("guid", {})) for item in nodes}
        orphans = {
            _guid_key(item.get("guid", {}))
            for item in nodes
            if _guid_key(item.get("parentIndex", {}).get("guid", {})) not in existing_keys
            and _guid_key(item.get("parentIndex", {}).get("guid", {})) != _guid_key(item.get("guid", {}))
        }
        if not orphans:
            break
        nodes = [item for item in nodes if _guid_key(item.get("guid", {})) not in orphans]

    data["node"] = nodes
    return data


def print_tree(data: dict, max_depth: int = 5) -> None:
    nodes = data["node"]

    # guid -> children
    children_map: dict = {}
    for item in nodes:
        own_key = _guid_key(item.get("guid", {}))
        parent_key = _guid_key(item.get("parentIndex", {}).get("guid", {}))
        if parent_key != own_key:
            children_map.setdefault(parent_key, []).append(item)

    # 自引用的节点为根节点
    roots = [
        item for item in nodes
        if _guid_key(item.get("guid", {})) == _guid_key(item.get("parentIndex", {}).get("guid", {}))
    ]

    def _print(node, depth, prefix):
        guid = node.get("guid", {})
        print(f"{prefix}guid(sessionID={guid.get('sessionID')}, localID={guid.get('localID')}) type={node.get('type', 'N/A')}")
        if depth >= max_depth:
            return
        own_key = _guid_key(guid)
        for child in children_map.get(own_key, []):
            _print(child, depth + 1, prefix + "  ")

    for root in roots:
        _print(root, 1, "")


if __name__ == "__main__":
    input_file = "data.json"
    output_file = "result.json"

    target_guid = {"sessionID": 57, "localID": 7281}

    with open(input_file, "r", encoding="utf-8") as f:
        data = json.load(f)

    print("=== 删除前树结构 ===")
    print_tree(data)

    result = delete_by_guid(data, target_guid)

    print("\n=== 删除后树结构 ===")
    print_tree(result)

    with open(output_file, "w", encoding="utf-8") as f:
        json.dump(result, f, ensure_ascii=False, indent=2)

    print(f"\n处理完成，剩余 {len(result['node'])} 条，已写入 {output_file}")
