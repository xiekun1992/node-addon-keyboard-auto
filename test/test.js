const keyboardAuto = require('../index')
const {performance} = require('perf_hooks')

// console.log(keyboardAuto)
setTimeout(() => {

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
    keyboardAuto.keydown('controlleft')
    keyboardAuto.keydown('v')
    keyboardAuto.keyup('v')
    keyboardAuto.keyup('controlleft')
    
    console.log(`${(performance.now() - st) / 10}ms`)

}, 3000)    
