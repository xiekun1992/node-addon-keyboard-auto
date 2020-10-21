const keyboardAuto = require('./build/Release/keyboard_auto.node');
keyboardAuto.initListener(function(res) {
    console.log(res)
    keyboardAuto.releaseListener()
})
module.exports = keyboardAuto