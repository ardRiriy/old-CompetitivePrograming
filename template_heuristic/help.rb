n = gets.split[-1].to_i
tmp = 0
File.open("res.txt", mode = "r+") do |f|
	s = f.read
	tmp += s.nil? ? 0 : s.to_i
	tmp += n
end
File.delete("res.txt")
File.open("res.txt", mode = "w") do |f|
	f.puts tmp
end
