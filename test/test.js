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
    describe('keyboard actions', function() {
      it('given key press should be listened', function(done) {
        keyboardAuto.event.once('keydown', function(event) {
          assert.equal(event.vkCode, 65)
        })
        keyboardAuto.event.once('keyup', function(event) {
          assert.equal(event.vkCode, 65)
          done()
        })
        keyboardAuto.keydown('a')
        keyboardAuto.keyup('a')
      })
    })
    describe('mouse down & up', function() {
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
    describe('mouse wheel actions', function() {
      it('given mouse scroll up should be listened', function(done) {
        keyboardAuto.event.once('mousewheel', function(event) {
          // console.log(event)
          assert.equal(event.direction, 120)
          done()
        })
        keyboardAuto.mousewheel(1)
      })
      it('given mouse scroll down should be listened', function(done) {
        keyboardAuto.event.once('mousewheel', function(event) {
          // console.log(event)
          assert.equal(event.direction, -120)
          done()
        })
        keyboardAuto.mousewheel(-1)
      })
    })
    describe('mouse move', function() {
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
