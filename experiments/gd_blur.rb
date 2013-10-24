#!/usr/bin/env ruby

# Basic exercising of the new library function.

require 'rubygems'
require 'gd2-ffij'
include GD2


im = Image.import(ARGV[0])
im.gaussian_blur!
im.export("blurry-img.png")

