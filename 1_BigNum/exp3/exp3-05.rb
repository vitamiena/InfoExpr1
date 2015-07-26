require 'open3'

output = Open3.capture3("./Exp3-05")

print output.first

res1 = output.first.split("\n")[1].delete(" ").to_i
res2 = output.first.split("\n")[3].to_i

num1 = (2**1023) / ((2**23)+1)
num2 = (2**1023) % ((2**23)+1)

if res1 == num1 && res2 == num2
  puts "整商・剰余ともに正しい"
elsif res1 == num1
  puts "剰余が異なる"
  print "正解：" + num1.to_s
  print "結果：" + res1.to_s
else
  puts "整商が異なる"
  print "正解：" + num2.to_s
  print "結果：" + res2.to_s
end
