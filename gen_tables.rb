# Max value in the sine wave
COUNTER_TOP = 124

# How many samples in a full sine wave
SAMPLES = 64

# Wave is shifted up so that "0" becomes half maximum amplitude (min amplitude is actual 0)
SCALE = COUNTER_TOP / 2

def eqn(t)
  (SCALE * (Math.sin(2.0 * Math::PI * t / SAMPLES) + 1.0)).floor
end

def gen_nums
  nums = (0...SAMPLES).map {|t| eqn(t)}
  STDERR.write(nums)
  STDERR.write("\n")
  nums
end

def format_nums(nums)
  out = []
  nums.each_with_index do |n, i|
    if i % 16 == 0
      out << "\n\t"
    end
    out << ("0x%02x, " % n)
  end
  out.join('')[0..-3]
end

def gen_tables
  nums = []
  gen_nums.each do |n|
    nums << (n & 0xFF)
  end
  puts "const uint8_t wav[#{SAMPLES}] = {#{format_nums(nums)}\n};"
end

gen_tables
