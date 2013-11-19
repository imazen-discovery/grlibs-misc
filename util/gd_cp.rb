#!/usr/bin/env ruby

# Read and write an image, just to see how GD messes with it.

require 'rubygems'

require 'optparse'

require 'gd2-ffij'
include GD2

# Add path to local modules
proc {
  $LOAD_PATH.unshift(File.dirname(__FILE__))
}.call()

input = ARGV[0]
output = ARGV[1]

#puts input, output

im = Image.import(input)
im.save_alpha = true
im.export(output)

