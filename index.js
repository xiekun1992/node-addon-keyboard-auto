const keyboardAuto = require('./build/Release/keyboard_auto.node');
const Emitter = require('events')

module.exports = function () {
  class autoEmitter extends Emitter {}
  const event = new autoEmitter();
  return {
    event: event,
    init() {
      keyboardAuto.initListener(function(ev) {
        switch (ev.event) {
          case 0: 
            event.emit('mousewheel', {
              event: 'mousewheel',
              x: ev.x,
              y: ev.y,
              button: ev.button,
              direction: ev.direction
            })
            break
          case 1: 
            event.emit('mousemove', {
              event: 'mousemove',
              x: ev.x,
              y: ev.y,
              button: ev.button,
              direction: ev.direction
            })
            break
          case 2:
            event.emit('mousedown', {
              event: 'mousedown',
              x: ev.x,
              y: ev.y,
              button: ev.button,
              direction: ev.direction
            }) 
            break
          case 3: 
            event.emit('mouseup', {
              event: 'mouseup',
              x: ev.x,
              y: ev.y,
              button: ev.button,
              direction: ev.direction
            })
            break
          case 4: 
            event.emit('keydown', {
              event: 'keydown',
              vkCode: ev.vkCode,
              scanCode: ev.scanCode
            })
            break
          case 5: 
            event.emit('keyup', {
              event: 'keyup',
              vkCode: ev.vkCode,
              scanCode: ev.scanCode
            })
            break
        }
      })
    },
    release: keyboardAuto.releaseListener,
    keydown: keyboardAuto.keydown,
    keyup: keyboardAuto.keyup,
    mousemove: keyboardAuto.mousemove,
    mousewheel: keyboardAuto.mousewheel,
    mousedown: keyboardAuto.mousedown,
    mouseup: keyboardAuto.mouseup,
  }
}