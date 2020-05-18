# node-addon-keyboard-auto [![Build Status](https://travis-ci.org/xiekun1992/node-addon-keyboard-auto.svg?branch=master)](https://travis-ci.org/xiekun1992/node-addon-keyboard-auto)
a nodejs addon for keyboard controlling, support windows and linux

## Dependecies
### linux platform
- nodejs (any version supports N-API)
- python2.x
- make 
- g++
- libx11-dev (if missing will cause `fatal error: X11/keysym.h: No such file or directory`)
- libxtst-dev (if missing will cause `fatal error: X11/extensions/XTest.h: No such file or directory`)

## build steps
- install dependecies
- npm install
- npm run build
