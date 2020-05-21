# node-addon-keyboard-auto [![Build Status](https://travis-ci.org/xiekun1992/node-addon-keyboard-auto.svg?branch=master)](https://travis-ci.org/xiekun1992/node-addon-keyboard-auto)
a nodejs addon for keyboard control, support windows and linux

## Usage
`javascript
const keyboardAuto = require('node-addon-keyboard-auto')
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

keyboardAuto.keydown('shiftleft')
keyboardAuto.keydown('>')
keyboardAuto.keyup('>')
keyboardAuto.keyup('shiftleft')

keyboardAuto.keydown('controlleft')
keyboardAuto.keydown('a')
keyboardAuto.keyup('a')
keyboardAuto.keyup('controlleft')
`

## Dependecies
### linux platform
- nodejs (any version supports N-API)
- python2.x
- make 
- g++
- libx11-dev (if missing will cause `fatal error: X11/keysym.h: No such file or directory`)
- libxtst-dev (if missing will cause `fatal error: X11/extensions/XTest.h: No such file or directory`)
### windows platform
- nodejs (any version supports N-API)
- python2.x
- visual studio 2017

## Build with docker
- docker pull xkfront/keyboard-auto:v1
- docker run -it --rm xkfront/keyboard-auto:v1 bash
- git clone https://github.com/xiekun1992/node-addon-keyboard-auto.git && cd node-addon-keyboard-auto
- npm install
- npm run build

## Build on local machine
- install dependecies
- npm install
- npm run build
