import json


def delete_by_parent_guid(data: dict, target_guid: dict) -> dict:
    """删除 data["node"] 中 parentIndex.guid 匹配 target_guid 的所有元素，返回原结构"""
    data["node"] = [
        item for item in data["node"]
        if item.get("parentIndex", {}).get("guid") != target_guid
    ]
    return data


if __name__ == "__main__":
    input_file = "data.json"
    output_file = "result.json"

    target_guid = {"sessionID": 57, "localID": 7281}

    with open(input_file, "r", encoding="utf-8") as f:
        data = json.load(f)

    result = delete_by_parent_guid(data, target_guid)

    with open(output_file, "w", encoding="utf-8") as f:
        json.dump(result, f, ensure_ascii=False, indent=2)

    print(f"处理完成，剩余 {len(result['node'])} 条，已写入 {output_file}")
