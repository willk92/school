# William Kelley
# CS417-OOP
# ruby2.rb

# If num mod 3 == 0 then you simply divide it by 3 since you can flip
# the light in the middle of each group of 3 to achieve desired result
def multipleOfThrees(num)
  puts num/3
end

# Since we only have to skip one to the end to cover the last two lights
# This result is similar to num+1(which results in %3 == 0)
def lightsMod2(num)
  value = num - 2
  puts ((value/3) + 1)
end

# The tricky one is %3 == 1
#
def lightsMod1(num)
  value = num - 4
# Determined for 4 lights, the minimum number of moves to turn all 4 on was 5
# Therefore I subtract 4 from the total lights to make it %3 == 0 and add 5
  puts ((value/3) + 5)
end

lights = 0

puts "How many lights are there?"
lights = gets.chomp
lights = lights.to_i

functionVersion = lights % 3

if(functionVersion == 0)
  multipleOfThrees(lights)
elsif(functionVersion == 1)
  lightsMod1(lights)
elsif(functionVersion == 2)
  lightsMod2(lights)
else
  puts "I have no idea"
end
