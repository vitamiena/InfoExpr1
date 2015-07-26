#!/usr/local/bin/ruby
require 'open3'

def create_input
  uni = rand(100)
  inp = ""
  uni.times do
    inp = inp + "%04d" % rand(10000) + " "
  end
  inp.chop!
  [uni, inp]
end


1000.times do
  inp1 = create_input
  inp2 = create_input

  res = Open3.capture3("echo '#{inp1[0]} #{inp1[1]} #{inp2[0]} #{inp2[1]}' > input.txt; ./Exp5-2 < input.txt")
  Open3.capture3("echo 'n1:#{inp1[0]} #{inp1[1]}\nn2:#{inp2[0]} #{inp2[1]}\n' >> test.txt")
  unless res.last.success?
    p res[1]
    exit 1
  end

  res1 = res[0].delete("\n").delete(" ").to_i
  n1 = inp1[1].delete(" ").to_i
  n2 = inp2[1].delete(" ").to_i
  res2 = n1.gcd(n2)

  if res1 == res2
    p true
  else
    p false
    p res1
    p res2
    exit 1
  end
end
