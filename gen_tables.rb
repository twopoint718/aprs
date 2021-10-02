class TableGenerator

  def initialize
    # Pull in #defines from the header file
    parse_header_defines('serial.h').each do |define|
      STDERR.write("#{define[:name]} = #{define[:value]}\n")
      TableGenerator.const_set(define[:name], define[:value])
    end
  end

  def eqn(t)
    (COUNTER_TOP/2 * (Math.sin(2.0 * Math::PI * t / TABLE_SIZE) + 1.0)).floor
  end

  def gen_nums
    nums = (0...TABLE_SIZE).map {|t| eqn(t)}
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
    puts "const uint8_t wav[#{TABLE_SIZE}] = {#{format_nums(nums)}\n};"
  end

private

  def parse_header_defines(filename)
    file = File.open(filename, 'r')
    defines = []
    file.each_line do |line|
      numeric = line.match(/^#define\s+([A-Za-z_]+)_([0-9]+)$/)
      define  = line.match(/^#define\s+([0-9A-Za-z_]+)\s*(.*)$/)
      if define
        if numeric
          defines << {name: numeric[1], value: numeric[2].to_i}
        else
          value = define[2] == '' ? true : define[2].to_i
          defines << {name: define[1], value: value}
        end
      end
    end
    defines
  end
end # class TableGenerator

tg = TableGenerator.new
tg.gen_tables
