require_relative 'q2a.rb'
if(ARGV.length < 1)
    puts "Missing file name"
    exit
end
file = File.open(ARGV[0]).read
file.each_line do |line|
    puts line unless HID_num(line) == nil
end