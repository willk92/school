# William Kelley
# CS417-OOP
# Getting feet wet with ruby
# feetwet1.rb

def occurences(list, key)
  return list.count(key)
end

nums = 1,2,3,1,1,2,3,4,5
num = 1

strings = "word", "string", "integer", "word", "word", "integer"
string = "integer"

characters = 'a','b','c','d','a','b','b','b'
character = 'b'

puts occurences(nums,num)
puts occurences(strings, string)
puts occurences(characters, character)
