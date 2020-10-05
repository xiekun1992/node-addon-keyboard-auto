const assert = require('assert')
const {performance} = require('perf_hooks')
let keyboardAuto = require('../index')()
const os = require('os')
// console.log(keyboardAuto)

if (os.platform() == 'linux' && !process.env.DISPLAY) {
    console.log('npm test will not run on linux server') // 没有GUI环境导致SegmentFault错误
    process.exit(0)
} else {
  before(function() {
    // console.log(keyboardAuto)
    keyboardAuto.init()
  })
  after(function() {
    keyboardAuto.release()
  })
  // describe('keyboard', function() {
  //   it('given a sequence actions should be automated', function() {
  //     // const st = performance.now()  
  //     keyboardAuto.keydown('a')
  //     keyboardAuto.keyup('a')
  //     // keyboardAuto.keydown('a')
  //     // keyboardAuto.keyup('a')
  //     // keyboardAuto.keydown('a')
  //     // keyboardAuto.keyup('a')
  //     // keyboardAuto.keydown('a')
  //     // keyboardAuto.keyup('a')
  //     // keyboardAuto.keydown('a')
  //     // keyboardAuto.keyup('a')
  //     // keyboardAuto.keydown('controlleft')
  //     // keyboardAuto.keydown('v')
  //     // keyboardAuto.keyup('v')
  //     // keyboardAuto.keyup('controlleft')
  //     // console.log(`${(performance.now() - st) / 10}ms`)
  //   })
  // })
  describe('keyboard_auto', function() {
    it('given keyboard actions should be listened', function(done) {
      keyboardAuto.event.on('keydown', function(event) {
        assert.equal(event.vkCode, 65, 'unexpected keydown vkCode')
      })
      keyboardAuto.event.on('keyup', function(event) {
        assert.equal(event.vkCode, 65, 'unexpected keyup vkCode')
        done()
      })
      keyboardAuto.keydown('a')
      keyboardAuto.keyup('a')
    })
    it('given mouse click actions should be listened', function(done) {
      keyboardAuto.event.on('mousedown', function(event) {
        console.log(event)
      })
      keyboardAuto.event.on('mouseup', function(event) {
        console.log(event)
      })
      done()
    })
    it('given mouse scroll actions should be listened', function(done) {
      keyboardAuto.event.on('mousewheel', function(event) {
        console.log(event)
      })
      done()
    })
    it('given mouse move actions should be listened', function(done) {
      keyboardAuto.event.on('mousemove', function(event) {
        console.log(event)
      })
      done()
    })
  })
}
