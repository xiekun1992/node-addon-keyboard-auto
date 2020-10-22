const assert = require('assert')
const {performance} = require('perf_hooks')
let keyboardAuto = require('../index')()
const os = require('os')
// console.log(keyboardAuto)
const linux = os.platform() == 'linux'
// keyboardAuto.init()
// keyboardAuto.event.on('keydown', function(event) {
//   console.log(event, keyboardAuto.keycodeToChar(event.vkCode))
// })

if (linux && !process.env.DISPLAY) {
    console.log('npm test will not run on linux server') // 没有GUI环境导致SegmentFault错误
    process.exit(0)
} else {
  before(function() {
    keyboardAuto.init()
  })
  after(function() {
    keyboardAuto.release()
  })
  describe('keyboard_auto', function() {
    describe('keyboard actions', function() {
      it('given key press should be listened', function(done) {
        keyboardAuto.event.on('keydown', function(event) {
          console.log('-------', event, keyboardAuto.keycodeToChar(event.vkCode))
          assert.equal(keyboardAuto.keycodeToChar(event.vkCode), 'a')
        })
        keyboardAuto.event.on('keyup', function(event) {
          assert.equal(keyboardAuto.keycodeToChar(event.vkCode), 'a')
          done()
        })
        keyboardAuto.keydown('a')
        keyboardAuto.keyup('a')
      })
    })
    xdescribe('mouse down & up', function() {
      it('given mouse left click should be listened', function(done) {
        keyboardAuto.event.once('mousedown', function(event) {
          // console.log(event)
          assert.equal(event.button, 1)
        })
        keyboardAuto.event.once('mouseup', function(event) {
          assert.equal(event.button, 1)
          done()
        })
        keyboardAuto.mousedown(1)
        keyboardAuto.mouseup(1)
      })
      it('given mouse middle click should be listened', function(done) {
        keyboardAuto.event.once('mousedown', function(event) {
          // console.log(event)
          assert.equal(event.button, 2)
        })
        keyboardAuto.event.once('mouseup', function(event) {
          assert.equal(event.button, 2)
          done()
        })
        keyboardAuto.mousedown(2)
        keyboardAuto.mouseup(2)
      })
      it('given mouse right click should be listened', function(done) {
        keyboardAuto.event.once('mousedown', function(event) {
          // console.log(event)
          assert.equal(event.button, 3)
        })
        keyboardAuto.event.once('mouseup', function(event) {
          assert.equal(event.button, 3)
          done()
        })
        keyboardAuto.mousedown(3)
        keyboardAuto.mouseup(3)
      })
    })
    xdescribe('mouse wheel actions', function() {
      it('given mouse scroll up should be listened', function(done) {
        keyboardAuto.event.once('mousewheel', function(event) {
          // console.log(event)
          assert.equal(event.direction, linux ? 1: 120)
          done()
        })
        keyboardAuto.mousewheel(1)
      })
      it('given mouse scroll down should be listened', function(done) {
        keyboardAuto.event.once('mousewheel', function(event) {
          // console.log(event)
          assert.equal(event.direction, linux ? -1: -120)
          done()
        })
        keyboardAuto.mousewheel(-1)
      })
    })
    xdescribe('mouse move', function() {
      it('given mouse move actions should be listened', function(done) {
        keyboardAuto.event.once('mousemove', function(event) {
          // console.log(event)
          assert.equal(event.x, 100)
          assert.equal(event.y, 200)
          done()
        })
        keyboardAuto.mousemove(100, 200)
      })
    })
  })
}
