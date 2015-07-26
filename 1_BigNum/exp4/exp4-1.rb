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


# 1000.times do
#   inp1 = create_input
#   inp2 = create_input

#   res = Open3.capture3("echo '#{inp1[0]} #{inp1[1]} #{inp2[0]} #{inp2[1]}' > input.txt; ./Exp4-1 < input.txt")
#   Open3.capture3("echo 'n1:#{inp1[0]} #{inp1[1]}\nn2:#{inp2[0]} #{inp2[1]}\n' >> test.txt")
#   unless res.last.success?
#     p res[0]
#     exit 1
#   end

#   nums = res.first.split("\n")
#   res1 = nums[1].delete(" ").to_i
#   res2 = nums[2].delete(" ").to_i

#   b1 = inp1[1].delete(" ").to_i
#   b2 = inp2[1].delete(" ").to_i

#   p b1
#   p b2

#   n1 = b1/b2
#   n2 = b1%b2

#   if res1 == n1 && res2 == n2
#     p "true"
#   else
#     p false
#     p res1
#     p n1
#     p res2
#     p n2
#     exit 1
#   end
# end
