# William Kelley
# CS417-OOP
# Create a Ruby script that defines a function occurrences(list,key)
# that takes an array list and object key and returns the number of
# elements in list that are equal to key. Include sufficient test code
# to test your program (either by hand or using Ruby's unit test framework).
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
