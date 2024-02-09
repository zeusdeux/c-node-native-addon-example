const addon = require("bindings")("my_addon"); // this name comes from target_name in binding.gyp

module.exports.hello = addon.hello;
