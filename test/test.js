const keyboardAuto = require('../index')
const {performance} = require('perf_hooks')
const os = require('os')
// console.log(keyboardAuto)

if (os.platform() == 'linux' && !process.env.DISPLAY) {
    console.log('npm test will not run on linux server') // 没有GUI环境导致SegmentFault错误
    process.exit(0)
} else {
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
}
