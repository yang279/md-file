---
name: html-page-builder
description: 根据用户一句话的网页需求,直接生成一个完整、可在浏览器打开的 HTML 页面。当用户说"做个落地页/登录页/定价页""设计一个 X 页面""帮我搭个 Y 的网页/UI",或任何要一张网页设计稿/页面的需求时,使用本 skill。即使用户描述很模糊、信息不全,也照样按常见设计模式补全并产出完整页面,不要反问个不停,不要只给片段——直接给出整页 HTML。
---

# HTML Page Builder

收到用户的网页需求后,你的产出是**一份完整、自包含、可直接在浏览器打开的 HTML 文件**。
内部按"想清楚结构 → 照模板拼装 → 自检"三步走,但**只把最终的 HTML 给用户**(除非用户要看中间思路)。

## 第一步:想清楚结构(在心里完成,不必输出)

把用户的话补全成一份明确的施工说明,确定下面几项:

- **页面类型**:landing(落地页)/ pricing(定价页)/ login(登录)/ signup(注册)/ dashboard(后台)/ contact(联系)/ generic(其他)。
- **区块序列**:按页面类型铺常见骨架,用户额外要的就加,明确不要的就去。
  - landing 默认:`nav → hero → feature-grid → testimonial → pricing-table → cta-band → footer`
  - login 默认:`nav → form → footer`
  - pricing 默认:`nav → hero(短) → pricing-table → faq → footer`
- **风格**:从用户描述里判断一个基调 —— professional(专业)/ minimal(极简)/ playful(活泼)/ bold(醒目)/ elegant(优雅)/ technical(技术感)。
- **主色**:用户给了就用;没给就按基调选一个合理的(默认 `#4F46E5`)。
- **明暗**:默认浅色(light)。

缺失信息一律**按常见设计模式补合理默认**,不要反问。只有当缺失项会彻底改变页面方向(比如根本不知道这是给谁的什么产品)时,才在 HTML 顶部用一行 HTML 注释 `<!-- 假设:... -->` 标出你的关键假设,然后照常给完整页面。

## 第二步:照模板拼装 HTML

**整页只用下面这一套设计系统**:一个统一的 `<style>`(颜色/间距/圆角都集中在 `:root` 变量里,改主题只改这里),加一组组件写法。你的工作是**把文案填进这些写法**,不要自己发明新的样式体系或写零散的内联样式。

### 页面外壳(每次都用这个骨架)

```html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>{{页面标题}}</title>
<style>
:root{
  --brand:#4F46E5; --brand-hover:#4338CA; --on-brand:#fff;
  --surface:#fff; --surface-alt:#f8fafc; --fg:#0f172a; --muted:#64748b; --border:#e2e8f0;
  --radius:12px; --maxw:1120px;
}
*{box-sizing:border-box;margin:0;padding:0}
body{font-family:system-ui,-apple-system,"Segoe UI",Roboto,"PingFang SC","Microsoft YaHei",sans-serif;
  color:var(--fg);background:var(--surface);line-height:1.6}
.wrap{max-width:var(--maxw);margin:0 auto;padding:0 24px}
section,header,footer{padding:80px 0}
h1{font-size:clamp(2rem,5vw,3.5rem);line-height:1.1;font-weight:700}
h2{font-size:2rem;font-weight:700;margin-bottom:8px}
h3{font-size:1.125rem;font-weight:600}
p{color:var(--muted)}
.btn{display:inline-block;padding:12px 24px;border-radius:var(--radius);font-weight:600;
  text-decoration:none;cursor:pointer;border:none;font-size:1rem}
.btn-primary{background:var(--brand);color:var(--on-brand)}
.btn-primary:hover{background:var(--brand-hover)}
.btn-secondary{background:var(--surface);color:var(--fg);border:1px solid var(--border)}
.btn-ghost{background:transparent;color:var(--brand)}
.grid{display:grid;gap:24px}
.card{background:var(--surface);border:1px solid var(--border);border-radius:var(--radius);padding:24px}
.alt{background:var(--surface-alt)}
.center{text-align:center}
.muted{color:var(--muted)}
@media(max-width:768px){section,header,footer{padding:48px 0}}
</style>
</head>
<body>
  <!-- 这里按区块序列依次放下面的组件 -->
</body>
</html>
```

> 换主题只需改 `:root` 里的 `--brand` 和 `--radius` 等;颜色一律用变量,不要在组件里写死色值或像素。

### 组件写法(按需选用,文案换成真实内容)

每个区块外层都标 `data-section="类型"`(方便以后程序识别),内部包一层 `.wrap` 控制宽度。

**nav(导航):**
```html
<header data-section="nav" style="padding:20px 0;border-bottom:1px solid var(--border)">
  <div class="wrap" style="display:flex;align-items:center;justify-content:space-between">
    <strong style="font-size:1.25rem">{{品牌名}}</strong>
    <nav style="display:flex;gap:32px;align-items:center">
      <a href="#" class="muted" style="text-decoration:none">{{链接}}</a>
      <a href="#" class="btn btn-primary">{{按钮文字}}</a>
    </nav>
  </div>
</header>
```

**hero(首屏,文左图右):**
```html
<section data-section="hero">
  <div class="wrap grid" style="grid-template-columns:1fr 1fr;align-items:center;gap:48px">
    <div>
      <h1>{{主标题}}</h1>
      <p style="font-size:1.25rem;margin:20px 0 32px">{{副标题}}</p>
      <div style="display:flex;gap:16px">
        <a href="#" class="btn btn-primary">{{主按钮}}</a>
        <a href="#" class="btn btn-secondary">{{次按钮}}</a>
      </div>
    </div>
    <img src="https://placehold.co/560x400" alt="{{有意义的图片描述}}" style="width:100%;border-radius:var(--radius)">
  </div>
</section>
```
(居中变体:去掉图片列,内容套 `.center`,按钮组居中。)

**feature-grid(卖点网格,通常 3 列):**
```html
<section data-section="feature-grid" class="alt">
  <div class="wrap">
    <h2 class="center">{{小标题}}</h2>
    <div class="grid" style="grid-template-columns:repeat(3,1fr);margin-top:48px">
      <div class="card">
        <h3>{{卖点标题}}</h3>
        <p style="margin-top:8px">{{卖点说明}}</p>
      </div>
      <!-- 重复 N 个 card,数量按内容定 -->
    </div>
  </div>
</section>
```

**pricing-table(价格表,通常 3 档,中间档高亮):**
```html
<section data-section="pricing-table">
  <div class="wrap">
    <h2 class="center">{{标题}}</h2>
    <div class="grid" style="grid-template-columns:repeat(3,1fr);margin-top:48px">
      <div class="card">
        <h3>{{档位名}}</h3>
        <p style="font-size:2.5rem;color:var(--fg);font-weight:700;margin:16px 0">{{价格}}<span style="font-size:1rem;color:var(--muted)">{{周期}}</span></p>
        <ul style="list-style:none;display:flex;flex-direction:column;gap:12px;margin:24px 0">
          <li class="muted">✓ {{特性}}</li>
        </ul>
        <a href="#" class="btn btn-secondary" style="width:100%;text-align:center">{{按钮}}</a>
      </div>
      <!-- 高亮档:给 card 加 style="border:2px solid var(--brand)",按钮用 btn-primary -->
    </div>
  </div>
</section>
```

**testimonial(用户评价):** 用 `.card` 装一段引用 + 署名,单条居中或多条网格。
**faq(常见问题):** 用 `.wrap` 内多个 `<div>`,每个含一个 `<h3>` 问题 + `<p>` 答案。
**form(表单,如登录):** `.card` 居中(`max-width:400px;margin:0 auto`),内含 `<label>+<input>` 若干 + 一个 `btn-primary` 提交。
**cta-band(行动号召条):**
```html
<section data-section="cta-band" style="background:var(--brand)">
  <div class="wrap center">
    <h2 style="color:var(--on-brand)">{{标题}}</h2>
    <p style="color:var(--on-brand);opacity:.85;margin:12px 0 28px">{{副文案}}</p>
    <a href="#" class="btn btn-secondary">{{按钮}}</a>
  </div>
</section>
```
**footer(页脚):** 深底或 `.alt`,内含若干列链接 + 版权行。

> 对于上面没给完整模板的区块(testimonial/faq/form/footer),沿用同样的约定:外层 `data-section`,内层 `.wrap`,只用既有的 `.card`/`.btn`/`.grid`/`.muted` 等类和 `:root` 变量,保持视觉一致。

## 第三步:自检(交付前在心里过一遍)

- [ ] 是一份**完整**的 HTML 文件:有 `<!DOCTYPE>`、`<head>`(含那段 `<style>`)、`<body>`,能直接保存成 `.html` 双击打开。
- [ ] 区块顺序和你定的骨架一致,每个区块都有 `data-section`。
- [ ] 颜色/圆角都走 `:root` 变量,没有写死的杂色或随手的像素。
- [ ] 所有 `<img>` 有有意义的 `alt`;所有按钮/链接是 `<a>` 或 `<button>`。
- [ ] 文案是具体、可用的真实文字,没有 "Lorem ipsum" 或 "标题占位"。
- [ ] 全页只有一个 `<h1>`。

## 输出方式

直接把完整 HTML 给用户(放进代码块即可)。除非用户要求,不要附带长篇解释——他们要的是页面本身。如果做了关键假设,用页面顶部的 HTML 注释一行带过即可。

---

## 示例

Input:`给开发者工具做个落地页,专业风,主色紫色`
你应当:把 `:root` 的 `--brand` 改成紫色(如 `#6D28D9`),按 landing 骨架依次输出 nav、hero(文左图右,标题如"更快地从想法到生产")、feature-grid(三个开发者向卖点)、pricing-table(Free/Pro/Enterprise,Pro 高亮)、cta-band、footer,全部用上面的设计系统,文案写成具体可用的中文,最后输出一份完整 HTML 文件。
