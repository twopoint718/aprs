# Resolution of the DAC in bits
DEPTH = 12

# How many samples in a full sine wave
SAMPLES = 256

SCALE = 1 << (DEPTH - 1)

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
  hi = [] # high byte
  lo = [] # low nybble
                              # Bit-pattern mask -> bit-pattern within byte
  gen_nums.each do |n|        # ABCD EFGH IJKL
    hi << ((n & 0xFF0) >> 4)  # 1111 1111 0000 -> ABCD EFGH
    lo << ((n & 0x00F) << 4)  # 0000 0000 1111 -> IJKL xxxx
  end

  puts "const uint8_t buf_hi[#{SAMPLES}] = {#{format_nums(hi)}\n};"
  puts "const uint8_t buf_lo[#{SAMPLES}] = {#{format_nums(lo)}\n};"
end

gen_tables
