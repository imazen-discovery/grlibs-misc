#!/usr/bin/env ruby

# Basic exercising of the new library function.

require 'rubygems'
require 'gd2-ffij'
include GD2


im = Image.import("tmp-images/shrunk/640/8s.png")
im.gaussian_blur!
im.export("blurry.png")



