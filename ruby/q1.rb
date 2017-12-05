def double(int_values)
    int_values.sort!
    int_values.each {|value| puts "#{value} #{2*value}"}
end