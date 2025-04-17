Vue (pronounced /vjuː/, like **view**) is a JavaScript framework for building user interfaces. It builds on top of standard HTML, CSS, and JavaScript and provides a <span style="background:#d3f8b6">declarative</span>, component-based programming model that helps you efficiently develop user interfaces of any complexity.

*Two features*.

Declarative Rendering. We can declaratively describe *HTML* output based on JavaScript state. Please refer to [[CS61A 4.3 Declarative Programming]] about some definitions for declarative programming.
[[Claude_What is declarative programming]]
[[Claude_Differences between assemly and declarative programming]]

Reactivity. Vue tracks JS state changes and efficiently updates the Document Object M? when changes happen.

*A progressive framework*.

Also a way to conquer the difficulty caused by the diversity of frontend dev. Its a *Framework*, *Ecosystem*. Vue can be used in the following:
- Enhancing static HTML, more simply
- Embedding as Web Components. ?Will it take up what H5 and CSS do?
- Single-Page Application. 
- Fullstack / SSR(Server-Side-Rendering)
- Jamstack / SSG(Static Site Generation)
- Targeting Desktop, mobile, WebGL, and even in *Terminal*?

why we call Vue "The Progressive Framework": <font color="#ffff00">it's a framework that can grow with you and adapt to your needs.</font>
### Single-File Components

abbr. SFC. A Vue SFC aka `*.vue` files. It encapsulates the components' logic(JavaScript, in what type and extent?) and template(*HTML*), and style(*CSS*).

### API styles

Vue components can be authored in two different API styles: **Options API** and **Composition API**.
*Options API*[​](https://vuejs.org/guide/introduction.html#options-api)

With Options API, we define a component's logic using an object of options such as `data`, `methods`, and `mounted`. Properties defined by options are exposed on `this` inside functions, which points to the component instance:
```vue
<script>
export default {
  // Properties returned from data() become reactive state
  // and will be exposed on `this`.
  data() {
    return {
      count: 0
    }
  },

  // Methods are functions that mutate state and trigger updates.
  // They can be bound as event handlers in templates.
  methods: {
    increment() {
      this.count++
    }
  },

  // Lifecycle hooks are called at different stages
  // of a component's lifecycle.
  // This function will be called when the component is mounted.
  mounted() {
    console.log(`The initial count is ${this.count}.`)
  }
}
</script>

<template>
  <button @click="increment">Count is: {{ count }}</button>
</template>
```

*Composition API*.
We define a *component*'s logic using imported API functions. In Single-File Components, this is typically used with `<script setup>`. The `setup` is an *attribute*. It is a *hint* that makes Vue perform compile-time transforms that allow us to use Composition API with less boilerplate :: repeated work.

```vue
<script setup>
import { ref, onMounted } from 'vue'

// reactive state
const count = ref(0)

// functions that mutate state and trigger updates
function increment() {
  count.value++
}

// lifecycle hooks
onMounted(() => {
  console.log(`The initial count is ${count.value}.`)
})
</script>

<template>
  <button @click="increment">Count is: {{ count }}</button>
</template>
```

The Options API is centered around the concept of a "component instance" (`this` as seen in the example), which typically aligns better with a *class-based* mental model for users coming from OOP language backgrounds. It is also more beginner-friendly by abstracting away the reactivity details and enforcing code organization via option groups.

The Composition API is centered around *declaring* reactive state variables directly in a function scope and composing state from multiple functions together to handle complexity. It is more free-form and requires an understanding of how reactivity works in Vue to be used effectively. In return, its flexibility enables more powerful patterns for organizing and reusing logic.





















