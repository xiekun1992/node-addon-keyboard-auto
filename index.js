const keyboardAuto = require('./build/Release/keyboard_auto.node');
const {performance} = require('perf_hooks')

keyboardAuto.init()
// setTimeout(() => {
const t = setInterval(() => {
  clearInterval(t)
  const st = performance.now()
  keyboardAuto.keydown('a')
  keyboardAuto.keyup('a')
  keyboardAuto.keydown('a')
  keyboardAuto.keyup('a')
  keyboardAuto.keydown('a')
  keyboardAuto.keyup('a')
  keyboardAuto.keydown('a')
  keyboardAuto.keyup('a')
  keyboardAuto.keydown('a')
  keyboardAuto.keyup('a')
  console.log(`${(performance.now() - st) / 10}ms`)
  keyboardAuto.destroy()
// }, 0)
}, 1000)
