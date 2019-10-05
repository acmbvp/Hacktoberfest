# vue-top-button

[![Latest Version](https://badgen.net/npm/v/vue-top-button)](https://www.npmjs.com/package/vue-top-button)

Scroll to page top button, Vue.js component.

## Demo

[Demo](https://tanahatas.me)


## Install

### Browser

```html
<script src="vue.js"></script>
<script src="vue-go-top.min.js"></script>
```


### npm

```
npm install --save vue-top-button
```


## Usage

### Browser

```html
<div id="app">
  <go-top></go-top>
</div>

<script src="vue.js"></script>
<script src="vue-go-top.min.js"></script>
<script>
Vue.use(GoTop);
new Vue({
  el: '#app'
});
</script>
```


### SFC

```vue
<template>
  <go-top></go-top>
</template>

<script>
import GoTop from 'vue-top-button';

export default {
  components: {
    GoTop
  }
}
</script>
```


## Props

| name           | type               | defaults                        | description                                 |
|----------------|--------------------|---------------------------------|---------------------------------------------|
| `:size`        | `Number`           | `70`                            | width/height pixel size                     |
| `:right`       | `String`, `Number` | `50`                            | margin from right                           |
| `:bottom`      | `String`, `Number` | `100`                           | margin from bottom                          |
| `:bottom-gap`  | `String`, `Number` | `0`                             | gap of bottom margin                        |
| `:z-index`     | `Number`           | `1000`                          | z-index size                                |
| `fg-color`     | `String`           | `#ffffff`                       | text color                                  |
| `bg-color`     | `String`           | `#ffc966`                       | background color                            |
| `:radius`      | `String`, `Number` | `50%`                           | border-radius size                          |
| `weight`       | `String`           | `normal`                        | line weight of arrow                        |
| `ripple-bg`    | `String`           | `rgba(255, 255, 255, .5)`       | ripple animation color                      |
| `:boundary`    | `Number`           | `200`                           | top position where the element is displayed |
| `:max-width`   | `Number`           | `640`                           | media query max-width(px)                   |
| `src`          | `String`           | `null`                          | image url                                   |
| `alt`          | `String`           | ``                              | alternative text for image                  |
| `:has-outline` | `Boolean`          | `true`                          | show outline when focus                     |
| `box-shadow`   | `String`           | `1px 1px 2px rgba(0, 0, 0, .3)` | box-shadow property                   |


## License

MIT


## Author

Ahmad Ainul Rizki
