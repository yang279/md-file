"""
Convert output.html to design DSL JSON format defined in 设计dsl.md.

Layout estimation strategy:
- Viewport: 1440px wide
- Each data-section maps to a top-level frame layer
- Elements are measured relative to their parent container
- Positions are estimated from CSS class patterns and inline styles
"""

import json
import re
import uuid
from typing import Optional
from bs4 import BeautifulSoup, Tag

# ── ID generation ──────────────────────────────────────────────────────────────
_session = "1"
_counter = [1]

def next_id() -> str:
    _id = f"{_session}:{_counter[0]}"
    _counter[0] += 1
    return _id

# ── CSS value helpers ──────────────────────────────────────────────────────────
def parse_px(value: str, fallback: float = 0) -> float:
    m = re.search(r"([\d.]+)px", value or "")
    return float(m.group(1)) if m else fallback

def parse_hex_color(value: str) -> Optional[str]:
    """Return 8-char HEX+Alpha string or None."""
    if not value:
        return None
    value = value.strip()
    m = re.search(r"#([0-9A-Fa-f]{3,8})", value)
    if not m:
        return None
    h = m.group(1)
    if len(h) == 3:
        h = "".join(c * 2 for c in h)
    if len(h) == 6:
        h += "FF"
    return "#" + h.upper()

def css_color_to_hex(value: str) -> Optional[str]:
    """Handle #hex and rgb(...) forms."""
    if not value:
        return None
    value = value.strip()
    if value.startswith("#"):
        return parse_hex_color(value)
    m = re.match(r"rgba?\((\d+),\s*(\d+),\s*(\d+)(?:,\s*([\d.]+))?\)", value)
    if m:
        r, g, b = int(m.group(1)), int(m.group(2)), int(m.group(3))
        a = int(float(m.group(4)) * 255) if m.group(4) else 255
        return "#{:02X}{:02X}{:02X}{:02X}".format(r, g, b, a)
    return None

# ── Inline style parser ────────────────────────────────────────────────────────
def parse_inline_style(style_str: str) -> dict:
    props = {}
    for part in (style_str or "").split(";"):
        if ":" in part:
            k, _, v = part.partition(":")
            props[k.strip().lower()] = v.strip()
    return props

# ── Font-size resolver (handles clamp()) ──────────────────────────────────────
def resolve_font_size(value: str) -> float:
    if not value:
        return 14
    value = value.strip()
    # clamp(min, preferred, max) → use preferred middle value
    m = re.match(r"clamp\(([^,]+),([^,]+),([^,]+)\)", value)
    if m:
        value = m.group(2).strip()
    return parse_px(value, 14)

# ── CSS class → design semantics ──────────────────────────────────────────────
BTN_CLASSES = {"btn", "btn-primary", "btn-secondary", "btn-ghost"}
CARD_CLASSES = {"card"}

def el_classes(el: Tag) -> set:
    return set(el.get("class") or [])

# ── 组件实例映射（对应 pix-split/harmony_out/component/ 中的组件集）────────────
# 变体选取原则：默认 Normal/Enabled 状态，灰色场景=OFF
COMPONENT_INSTANCES = {
    # <input type="text/email/password"> → TextInput-Box-Phone
    "text_input": {
        "symbol_id":             "40:34721",   # 灰色场景=OFF,状态=Normal
        "variant_key":           "698f83c7c28a321a105e40cde98616611f668d8d",
        "component_set_key":     "2a32df63656ddde67ed3758de2043188b51234c6",
        "component_set_resolved": True,
        "variant_props":         {"灰色场景": "OFF", "状态": "Normal"},
        "default_w":             360,
        "default_h":             56,
    },
    # <input type="checkbox"> → CheckBox-Phone
    "checkbox": {
        "symbol_id":             "1:10061",    # Selected=OFF,状态=Enabled
        "variant_key":           "3c7ba0ae81232ec365d583991bfb516d63884be6",
        "component_set_key":     "046927ae52510fcabba0878576981637ffddf698",
        "component_set_resolved": True,
        "variant_props":         {"Selected": "OFF", "状态": "Enabled"},
        "default_w":             24,
        "default_h":             24,
    },
}

def make_instance_layer(comp_type: str, el: Tag, x: float, y: float, parent_w: float) -> dict:
    comp = COMPONENT_INSTANCES[comp_type]
    w = parent_w if comp_type == "text_input" else comp["default_w"]
    h = comp["default_h"]
    label = (el.get("placeholder") or el.get("id") or el.get("type") or comp_type)[:40]
    return {
        "id": next_id(),
        "name": label,
        "type": "instance",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": w, "height": h},
        "instance": {
            "symbol_id":             comp["symbol_id"],
            "variant_key":           comp["variant_key"],
            "component_set_key":     comp["component_set_key"],
            "component_set_resolved": comp["component_set_resolved"],
            "variant_props":         comp["variant_props"],
            "overrides":             [],
        },
    }

# ── Layout constants ───────────────────────────────────────────────────────────
VIEWPORT_W = 1440
MAX_CONTENT_W = 1120
GUTTER = (VIEWPORT_W - MAX_CONTENT_W) // 2  # 160 each side

SECTION_HEIGHTS = {
    "nav":           64,
    "hero":         560,
    "feature-grid": 600,
    "testimonial":  420,
    "pricing-table":620,
    "faq":          520,
    "cta-band":     280,
    "footer":       320,
}
DEFAULT_SECTION_H = 400

# ── Layer builders ─────────────────────────────────────────────────────────────

def make_text_layer(el: Tag, x: float, y: float, w: float, h: float) -> dict:
    text = el.get_text(strip=True)
    style = parse_inline_style(el.get("style", ""))
    classes = el_classes(el)

    font_size = resolve_font_size(style.get("font-size", ""))
    if not font_size:
        tag = el.name
        font_size = {"h1": 48, "h2": 32, "h3": 18, "h4": 16, "p": 14, "span": 14,
                     "li": 14, "label": 14, "a": 14, "strong": 16}.get(tag, 14)

    raw_weight = style.get("font-weight", "")
    font_style = "Bold" if raw_weight in ("700", "bold") or el.name in ("h1","h2","h3","strong") else "Regular"

    raw_color = style.get("color", "")
    color = css_color_to_hex(raw_color)
    if not color:
        color = "#64748BFF" if "muted" in classes else "#0F172AFF"

    align_h = "center" if "center" in (style.get("text-align","") + " ".join(classes)) else "left"

    return {
        "id": next_id(),
        "name": text[:30] if text else el.name,
        "type": "text",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": w, "height": h},
        "text_content": text,
        "text_style": {
            "font_family": "PingFang SC",
            "font_style": font_style,
            "font_size": font_size,
            "color": color,
            "letter_spacing": 0,
            "line_height": "auto",
            "align_h": align_h,
            "align_v": "center",
        },
    }

def make_image_layer(el: Tag, x: float, y: float, w: float, h: float) -> dict:
    alt = el.get("alt", "image")
    return {
        "id": next_id(),
        "name": alt[:40],
        "type": "rectangle",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": w, "height": h},
        "fills": [{"type": "image", "visible": True, "opacity": 1, "image_hash": "placeholder"}],
        "corner_radius": 12,
    }

def make_button_layer(el: Tag, x: float, y: float) -> dict:
    text = el.get_text(strip=True)
    classes = el_classes(el)
    w, h = 160, 44
    bg = "#4F46E5FF" if "btn-primary" in classes else "#FFFFFFFF"
    fg = "#FFFFFFFF" if "btn-primary" in classes else "#0F172AFF"
    layer: dict = {
        "id": next_id(),
        "name": f"Button/{text[:20]}",
        "type": "frame",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": w, "height": h},
        "fills": [{"type": "solid", "visible": True, "opacity": 1, "color": bg}],
        "corner_radius": 12,
        "auto_layout": {
            "direction": "horizontal",
            "gap": 0,
            "counter_gap": 0,
            "padding": [12, 24, 12, 24],
            "align_items": "center",
            "justify_content": "center",
            "wrap": False,
        },
        "children": [make_text_layer(el, 0, 0, w - 48, 20)],
    }
    layer["children"][0]["text_style"]["color"] = fg
    return layer

def make_card_layer(el: Tag, x: float, y: float, w: float, h: float) -> dict:
    children = []
    cy = 24
    for child in el.children:
        if not isinstance(child, Tag):
            continue
        child_layer = convert_element(child, 24, cy, w - 48)
        if child_layer:
            children.append(child_layer)
            cy += child_layer["box"]["height"] + 8

    return {
        "id": next_id(),
        "name": "Card",
        "type": "frame",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": w, "height": max(h, cy + 24)},
        "fills": [{"type": "solid", "visible": True, "opacity": 1, "color": "#FFFFFFFF"}],
        "strokes": [{"type": "solid", "visible": True, "opacity": 1, "color": "#E2E8F0FF"}],
        "corner_radius": 12,
        "children": children,
    }

# ── Generic element converter ──────────────────────────────────────────────────

def convert_element(el: Tag, x: float, y: float, parent_w: float) -> Optional[dict]:
    """Convert a single HTML element to a DSL layer. Returns None for skipped elements."""
    if el.name is None:
        return None

    tag = el.name.lower()
    classes = el_classes(el)
    style = parse_inline_style(el.get("style", ""))

    # Skip non-visual containers with no meaningful content
    if tag in ("script", "style", "meta", "link", "head"):
        return None

    # ── Button ────────────────────────────────────────────────────────────────
    if classes & BTN_CLASSES or (tag in ("a", "button") and "btn" in " ".join(classes)):
        return make_button_layer(el, x, y)

    # ── Input → instance ──────────────────────────────────────────────────────
    if tag == "input":
        input_type = el.get("type", "text").lower()
        if input_type == "checkbox":
            return make_instance_layer("checkbox", el, x, y, parent_w)
        elif input_type not in ("submit", "button", "reset", "hidden"):
            return make_instance_layer("text_input", el, x, y, parent_w)
        return None

    # ── Image ─────────────────────────────────────────────────────────────────
    if tag == "img":
        raw_w = parse_px(style.get("width", ""), parent_w * 0.5)
        if "100%" in style.get("width", ""):
            raw_w = parent_w
        return make_image_layer(el, x, y, raw_w, raw_w * 0.75)

    # ── Text leaf elements ────────────────────────────────────────────────────
    if tag in ("h1", "h2", "h3", "h4", "p", "span", "label", "li", "strong", "em"):
        font_size_map = {"h1": 48, "h2": 32, "h3": 18, "h4": 16, "p": 14}
        fs = font_size_map.get(tag, 14)
        h = fs * 1.5
        return make_text_layer(el, x, y, parent_w, h)

    # ── Anchor / link ─────────────────────────────────────────────────────────
    if tag == "a":
        text = el.get_text(strip=True)
        if text:
            return make_text_layer(el, x, y, min(len(text) * 9, parent_w), 20)
        return None

    # ── Card ──────────────────────────────────────────────────────────────────
    if classes & CARD_CLASSES:
        return make_card_layer(el, x, y, parent_w, 200)

    # ── Generic container (div, nav, ul, ol, ...) → frame ────────────────────
    children = []
    cy = 0
    for child in el.children:
        if not isinstance(child, Tag):
            continue
        child_layer = convert_element(child, 0, cy, parent_w)
        if child_layer:
            children.append(child_layer)
            cy += child_layer["box"]["height"] + 8

    if not children:
        return None

    h = cy
    return {
        "id": next_id(),
        "name": el.get("id") or el.get("class", [tag])[0] if el.get("class") else tag,
        "type": "frame",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": x, "y": y, "width": parent_w, "height": h},
        "fills": [],
        "children": children,
    }

# ── Section → frame ────────────────────────────────────────────────────────────

def convert_section(el: Tag, y_offset: float) -> dict:
    section_type = el.get("data-section", "section")
    section_h = SECTION_HEIGHTS.get(section_type, DEFAULT_SECTION_H)

    style = parse_inline_style(el.get("style", ""))
    bg_raw = style.get("background", style.get("background-color", ""))
    if section_type in ("feature-grid", "footer"):
        bg_color = "#F8FAFCFF"
    elif section_type == "cta-band":
        bg_color = "#4F46E5FF"
    else:
        bg_color = css_color_to_hex(bg_raw) or "#FFFFFFFF"

    # Build children from .wrap content
    children = []
    wrap = el.find(class_="wrap") or el
    content_x = GUTTER
    cy = 80  # default section padding-top

    for child in wrap.children:
        if not isinstance(child, Tag):
            continue
        child_layer = convert_element(child, content_x, cy, MAX_CONTENT_W)
        if child_layer:
            children.append(child_layer)
            cy += child_layer["box"]["height"] + 24

    return {
        "id": next_id(),
        "name": f"Section/{section_type}",
        "type": "frame",
        "visible": True,
        "opacity": 1,
        "blend_mode": "normal",
        "box": {"x": 0, "y": y_offset, "width": VIEWPORT_W, "height": section_h},
        "fills": [{"type": "solid", "visible": True, "opacity": 1, "color": bg_color}],
        "children": children,
    }

# ── Main conversion ────────────────────────────────────────────────────────────

def html_to_dsl(html_path: str) -> dict:
    with open(html_path, "r", encoding="utf-8") as f:
        soup = BeautifulSoup(f.read(), "html.parser")

    title = soup.find("title")
    file_name = title.get_text(strip=True) if title else "output"

    sections = soup.find_all(attrs={"data-section": True})

    page_layers = []
    y = 0
    for el in sections:
        layer = convert_section(el, y)
        page_layers.append(layer)
        y += layer["box"]["height"]

    return {
        "meta": {
            "version": "1.0.0",
            "source": "html-export",
            "file_id": "html-" + uuid.uuid4().hex[:12],
            "file_name": file_name,
            "created_at": "2026-06-02T00:00:00Z",
            "updated_at": "2026-06-02T00:00:00Z",
        },
        "pages": [
            {
                "id": "0:1",
                "name": "Page 1",
                "layers": page_layers,
            }
        ],
    }

# ── Entry point ────────────────────────────────────────────────────────────────

if __name__ == "__main__":
    import sys
    src = sys.argv[1] if len(sys.argv) > 1 else "output.html"
    dst = sys.argv[2] if len(sys.argv) > 2 else "output_dsl.json"

    dsl = html_to_dsl(src)
    with open(dst, "w", encoding="utf-8") as f:
        json.dump(dsl, f, ensure_ascii=False, indent=2)

    total_layers = sum(
        1 + len(p.get("children", []))
        for page in dsl["pages"]
        for p in page["layers"]
    )
    print(f"Done → {dst}  ({len(dsl['pages'][0]['layers'])} sections, ~{total_layers} layers)")
