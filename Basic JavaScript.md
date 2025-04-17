客户端 JavaScript 语言的核心包含一些普遍的编程特性，以让你可以做到如下的事情：

- 在变量中储存有用的值。比如上文的示例中，我们请求客户输入一个新名字，然后将其储存到 `name` 变量中。
- 操作一段文本（在编程中称为“字符串”（string））。上文的示例中，我们取字符串“玩家 1：”，然后把它和 `name` 变量拼接起来，创造出完整的文本标签，比如“玩家 1：小明”。
- 运行代码以响应网页中发生的特定事件。上文的示例中，我们用一个 [`click`](https://developer.mozilla.org/zh-CN/docs/Web/API/Element/click_event "click") 事件来检测按钮什么时候被点击，然后运行代码更新文本标签。
- 以及更多！

### Web API

Browswer APIs are built inside  Web Browsers. They can filter data out from surrounding computer environment, and some other *complex work*.

*DOM API*. It can operate on HTML and CSS, by *creating, removing and editing and applying new styles*. A poped messagebox or some newly-displayed content, are caused by running  *DOM*.

*Position API*
*Canvas and WebGL* API.
*HTMLMediaElement* and *WebRTC*, [影音类 API](https://developer.mozilla.org/en-US/docs/Web/Media/Guides/Audio_and_video_delivery)
*Third-Party APIs*. Like Google Map API.

### What does JS do?

Making static sites alive, by dynamically editing HTML and CSS, through DOM API.

>IE tables are independent containers running codes, and in most cases, the codes run completely independently.

*There are specific sequence for JS code to run*. 

```js
const button = document.querySelector("button");

button.addEventListener("click", updateName);

function updateName() {
  const name = prompt("输入一个新的名字：");
  button.textContent = `玩家 1：${name}`;
}
```

### Adding JS code into pages

using `<script>` to insert code into the page.




















