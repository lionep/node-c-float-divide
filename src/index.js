'use strict';
const addon = require('../build/Release/addon');

function divide(numerator, denominator) {
  const result = addon.divide(numerator, denominator);
  return result.replace(/\.?0+$/g, '');
}

module.exports = divide;
