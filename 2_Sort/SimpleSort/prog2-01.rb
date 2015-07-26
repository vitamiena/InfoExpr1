#! /usr/local/bin/ruby
require 'open3'
print "m = "; m = gets.to_i
p = []
(0..10).to_a.each do |i|
  p[i] = i/10.0
  puts p[i]
end

p.each_with_index do |i, k|
  Open3.capture3("echo '#{m} #{i}' > rinput.txt; ./Rand < rinput.txt >input#{"%02d" % k}.txt")
end

fname = ["ins_cmp_output", "ch_cmp_output", "ins_swp_output", "sel_swp_output"]

(0..10).to_a.each do |i|
  Open3.capture3("./Sort 3 100 1 1000 < input#{"%02d" % i}.txt > #{fname[0] + "%02d" % i}.txt")
  Open3.capture3("./Sort 2 100 1 1000 < input#{"%02d" % i}.txt > #{fname[1] + "%02d" % i}.txt")
  Open3.capture3("./Sort 3 100 2 1000 < input#{"%02d" % i}.txt > #{fname[2] + "%02d" % i}.txt")
  Open3.capture3("./Sort 1 100 2 1000 < input#{"%02d" % i}.txt > #{fname[3] + "%02d" % i}.txt")
end

a1 = Array.new
(0..3).to_a.each do |f|
  (0..10).to_a.each do |i|
    filename = "#{fname[f] + "%02d" % i}.txt"
    a1[i] = File.read(filename).delete("\n")
    File.unlink filename
  end
  File.open(fname[f]+".csv", "w") do |file|
    (0..10).to_a.each do |i|
      file.puts a1[i]
    end
  end
end
