<template>
  <transition name="vue-go-top">
    <div
      v-if="isActive && enabled"
      :style="mainStyle"
      role="button"
      tabindex="1"
      class="vue-go-top"
      @click.prevent="clickHandle"
      @keydown.prevent="keyEnter">
      <div
        v-if="src !== null"
        class="vue-go-top__icon">
        <img
          :src="src"
          :alt="alt"
          class="vue-go-top__image">
        <div
          :is-active="isRippleActive"
          :style="rippleStyle"
          class="vue-go-top__ripple"/>
      </div>
      <div
        v-else
        class="vue-go-top__content">
        <div
          :is-active="isRippleActive"
          :style="rippleStyle"
          class="vue-go-top__ripple"/>
        <slot/>
      </div>
    </div>
  </transition>
</template>

<script>
import { throttle } from 'throttle-debounce';
import SweetScroll from 'sweet-scroll';

const KEY_ENTER = 13;
const RIPPLE_DURATION = 750;
const THROTTLE_DELAY = 100;

const makeBgImage = (weight, fgColor) => {
  const color = fgColor.replace(/^#/, '');
  if (weight === 'bold') {
    return 'data:image/svg+xml;charset=utf8, %3Csvg version=%271.1%27 xmlns=%27http://www.w3.org/2000/svg%27 width=%2710px%27 height=%2710px%27%3E %3Cpolygon fill=%27%23' + color + '%27 stroke=%27none%27 points=%278.646,7.354 5,3.707 1.354,7.354 0.646,6.646 5,2.293 9.354,6.646%27 /%3E %3C/svg%3E';
  }
  return 'data:image/svg+xml;charset=utf8,%3Csvg version=%271.1%27 xmlns=%27http://www.w3.org/2000/svg%27 width=%2710px%27 height=%2710px%27%3E %3Cpolygon fill=%27%23' + color + '%27 stroke=%27none%27 points=%278.589,6.945 5,3.22 1.413,6.945 1.052,6.598 5,2.499 8.948,6.598%27 /%3E %3C/svg%3E';
};

const fmtProp = (value, unit = 'px') => {
  return typeof value === 'number' ? value + unit : value;
};

const scroller = new SweetScroll();

export default {
  props: {
    size: {
      type: Number,
      default: 70
    },
    right: {
      type: [String, Number],
      default: 50
    },
    bottom: {
      type: [String, Number],
      default: 100
    },
    bottomGap: {
      type: [String, Number],
      default: 0
    },
    zIndex: {
      type: Number,
      default: 1000
    },
    fgColor: {
      type: String,
      default: '#ffffff'
    },
    bgColor: {
      type: String,
      default: '#ffc966'
    },
    radius: {
      type: [String, Number],
      default: '50%'
    },
    weight: {
      type: String,
      default: 'normal'
    },
    rippleBg: {
      type: String,
      default: 'rgba(255, 255, 255, .5)'
    },
    boundary: {
      type: Number,
      default: 200
    },
    maxWidth: {
      type: Number,
      default: 640
    },
    src: {
      type: String,
      default: null
    },
    alt: {
      type: String,
      default: ''
    },
    hasOutline: {
      type: Boolean,
      default: true
    },
    boxShadow: {
      type: String,
      default: '1px 1px 2px rgba(0, 0, 0, .3)'
    }
  },
  data() {
    const outline = this.hasOutline ? {} : { outline: '0 none' };
    return {
      enabled: false,
      isActive: false,
      isRippleActive: false,
      mainStyle: {
        width: fmtProp(this.size),
        height: fmtProp(this.size),
        right: fmtProp(this.right),
        bottom: `calc(${fmtProp(this.bottom)} - ${fmtProp(this.bottomGap)})`,
        zIndex: this.zIndex,
        color: this.fgColor,
        backgroundColor: this.bgColor,
        backgroundImage: `url("${makeBgImage(this.weight, this.fgColor)}")`,
        backgroundSize: `${this.size} auto`,
        boxShadow: this.boxShadow,
        opacity: this.opacity,
        borderRadius: fmtProp(this.radius),
        ...outline,
      },
      rippleStyle: {
        top: fmtProp(-this.size),
        left: fmtProp(-this.size),
        width: '200%',
        height: '200%',
        backgroundColor: this.rippleBg
      },
      throttleScroll: null,
      throttleResize: null
    };
  },
  created() {
    this.handleResize();
    this.throttleScroll = throttle(THROTTLE_DELAY, this.handleScroll);
    this.throttleResize = throttle(THROTTLE_DELAY, this.handleResize);
    window.addEventListener('resize', this.throttleResize);
    window.addEventListener('scroll', this.throttleScroll);
  },
  beforeDestroy() {
    if (this.throttleResize) {
      window.removeEventListener('resize', this.throttleResize);
    }
    if (this.throttleScroll) {
      window.removeEventListener('scroll', this.throttleScroll);
    }
  },
  methods: {
    clickHandle(e) {
      if (!this.isRippleActive) {
        const elTarget = e.target;
        if (elTarget) {
          const rect = elTarget.getBoundingClientRect();
          const top = e.clientY - rect.top;
          const left = e.clientX - rect.left;
          this.rippleStyle.top = fmtProp(top - this.size);
          this.rippleStyle.left = fmtProp(left - this.size);
        }
        this.isRippleActive = true;
        setTimeout(() => {
          this.isRippleActive = false;
        }, RIPPLE_DURATION);
      }
      scroller.to(0);
    },
    handleScroll() { // toggle display by scrolling.
      this.isActive = window.pageYOffset > this.boundary;
    },
    handleResize() {
      if (this.maxWidth > 0) {
        this.enabled = !window.matchMedia(`(max-width: ${this.maxWidth}px)`).matches;
      } else {
        this.enabled = true;
      }
    },
    keyEnter(e) {
      if (e.keyCode === KEY_ENTER) {
        scroller.to(0);
      }
    }
  },
};
</script>

<style lang="scss" scoped>
.vue-go-top {
  overflow: hidden;
  position: fixed;
  cursor: pointer;
  background-repeat: no-repeat;
  background-position: 50% 50%;
  background-size: 70% auto;
  white-space: nowrap;
  text-indent: 100%;

  &__content {
    position: relative;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
  }

  &__ripple {
    position: absolute;
    border-radius: 50%;
    transform: scale(0);
    opacity: 0;
    pointer-events: none;

    &[is-active] {
      animation: vue-go-top-ripple-animation .75s ease-out;
    }
  }

  &__icon {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
  }

  &__image {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    object-fit: cover;
  }
}

.vue-go-top-enter-active,
.vue-go-top-leave-active {
  transition: opacity .3s, transform .3s;
}
.vue-go-top-enter,
.vue-go-top-leave-to {
  opacity: 0;
  transform: translateY(50px);
}

@keyframes vue-go-top-ripple-animation {
  from {
    opacity: 1;
  }
  to {
    transform: scale(2);
    opacity: 0;
  }
}
</style>
