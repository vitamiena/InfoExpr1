#! /usr/local/bin/ruby
require 'open3'
print "uni = "
uni = gets.to_i
print "N1[] = "
n1 = gets.delete("\n")
print "E = "
e = gets.to_i

res = Open3.capture3("make BigNum; echo '#{uni} #{n1} #{e}' > input.txt;./BigNum < input.txt")

unless res.last.success?
  p res[1]
  exit 0
end

res1 = res[0].delete("\n").sub(/^.*=/, "").delete(" ").to_i
n1 = n1.delete("\n").delete(" ").to_i
res2 = n1**e
if res1 == res2
  p true
  print "正答：\n#{res1}\n"
else
  p false
  print "回答：\n#{res1}\n"
  print "正答：\n#{res2}\n"
end
