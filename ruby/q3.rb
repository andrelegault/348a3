require 'date'

if (ARGV.length < 1)
  puts "Missing filename"
  exit
end

db = {}
errors = []

file = File.open(ARGV[0]).read
file.each_line do |line|
    regex = line.match(/^(\d{4}): ((?=[[:upper:]]+[[:lower:]]+|[[:lower:]]+[[:upper:]]).+),\s*([[:upper:]]{4}),\s*(\d{2}[[:upper:]]{3}\d{2})$/)
    if(regex)
        groups = regex.captures
        puts groups[3]
        id = groups[0]
        name = groups[1]
        category = groups[2]
        date = Date.strptime(groups[3], '%d%b%y')
        el = db[id] unless db == nil
        if el == nil
            db[id] = {"name" => name, "category" => category, "date" => groups[3]}
        else
            now = Date.today
            inDate = Date.strptime(el["date"], '%d%b%y')
            el["date"] = groups[3] unless inDate - now < date - now
        end
    else
        errors.push("ERROR #{line}")
    end
end

categories = {}
by_category = db.sort_by { |id, item| item[:category] }
by_name = db.sort_by { |id, item| item[:name] }
by_category.each do |item|
    if categories[item[1]["category"]] == nil
        categories[item[1]["category"]] = [item[1]["name"]]
    else
        categories[item[1]["category"]].push(item[1]["name"])
    end
end
puts errors
puts "CATEGORIES"
categories.each do |category, items|
    puts "#{category}, #{items.length}, #{items.join(", ")}"
end
puts "ITEMS"
by_name.each {|item| puts "#{item[0]}: #{item[1]["name"]}, #{item[1]["date"]}" }