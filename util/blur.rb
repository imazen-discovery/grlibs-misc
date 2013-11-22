#!/usr/bin/env ruby

# Simplified version of gd_resize.rb that resizes one image.
require 'pry'  # DEBUG! REMOVE!
require 'rubygems'

require 'optparse'

require 'gd2-ffij'
include GD2

# Add path to local modules
proc {
  $LOAD_PATH.unshift(File.dirname(__FILE__))
#  $LOAD_PATH.uhshift(
}.call()


def blur(input, radius, output)
  im = Image.import(input)

  result = im.blurred(radius)
  
  opts = {}
  case File.extname(output).downcase.to_sym
  when :jpg, :jpeg
    opts[:quality] = 100
    
    # ... more goes here, maybe ...
  end

  result.save_alpha = true  # this is off by default
  moveOldFile(output)
  result.export(output, opts)
end


# Rename file 'name' to something different and (probably) unique
def moveOldFile(name)
  return unless File.file?(name)

  count = 0
  while true
    count += 1
    nfn = "#{name}.#{count}"

    if !File.file?(nfn)
      File.rename(name, nfn)
      break
    end
  end
end



def main
  truecolor = false
  mode = 'bicubic'
  blur = false
  sharpenPct = 0

  # OptionParser.new do |opts|
  #   opts.banner =
  #     "Usage: #{__FILE__} <ifile> <width> [<height>|'-'] <ofile>..."


  #   opts.on('--force-truecolor', "Force input images to truecolor.") {
  #     truecolor = true
  #   }

  #   opts.on('--interp MODE', '--mode MODE', 
  #           "Use interpolation mode 'MODE'.") { |im|
  #     raise "Unknown interpolation mode '#{im}'" unless MODES.has_key?(im)
  #     mode = im
  #   }

  #   opts.on('--modes', "List all interpolation modes and exit.") {
  #     print MODES.keys.sort.join("\n"), "\n"
  #     exit 0
  #   }

  #   opts.on('--blur', "Pre-filter image with a gaussian blur.") { |im|
  #     blur = true
  #   }

  #   opts.on('--sharpen PERCENT', Float, "Sharpen the resulting image.") { |im|
  #     sharpenPct = im.round
  #     if sharpenPct <= 0
  #       puts "Invalid sharpen percentage: #{sharpenPct}"
  #       exit 1
  #     end
  #   }
  # end.parse!

  if ARGV.size != 3
    puts "USAGE: resize <input> <radius> <output>"
    exit 1
  end

  r = ARGV[1].to_i
  if r == 0
    puts "Invalid radius: #{r}"
    exit 1
  end

  blur ARGV[0], r, ARGV[2]
end


main()

