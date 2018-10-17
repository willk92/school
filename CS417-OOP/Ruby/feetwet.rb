# William Kelley
# CS417-OOP
# https://stackoverflow.com/questions/13659696/find-indices-of-elements-that-match-a-given-condition
# https://stackoverflow.com/questions/21566397/finding-the-index-of-second-smallest-number-in-the-list
# feetwet.rb

def occurences(list, key)
  return list.count(key)
end

def numSmaller(list, item)
  if list.count() > 0
    numElements = list.find_all { |x| x < item }
    return numElements.count()
  else
    return "Array not of size 1 or larger"
  end
end

def secondSmallest(list)
  mn = list.min
  mx = list.max
  list.map! { |e| e == mn ? mx : e }
  num = list.min
  arr = list.each_index.select{|i| list[i] == num}
  val = 0
  if arr.count() > 1
    val = arr[1]
  else
    val = arr[0]
  end
  return val
end

def iterativeMap(list)
  list.each do |i|
    list[i-1] = list[i-1] * 2
  end
  return list
end

def recursiveMap(list, index)
  if index < 0
    return list
  else
    list[index] = list[index] * 2
    recursiveMap(list, index-1)
  end
end

nums = 1,2,3,1,1,2,3,4,5
num = 3

strings = "word", "string", "integer", "word", "word", "integer"
string = "integer"

characters = 'a','b','c','d','a','b','b','b'
character = 'b'

fails = []
willfail = 0

iterMap = 1,2,3
recMap = 1,2,3

puts " "
puts "---Problem 1---"
puts "Problem 1: Numbers"
puts occurences(nums,num)
puts "Problem 1: Strings"
puts occurences(strings, string)
puts "Problem 1: Characters"
puts occurences(characters, character)

puts " "
puts "---Problem 2---"
puts "Problem 2: Succeeding"
puts numSmaller(nums,num)
puts "Problem 2: Failing Case"
puts numSmaller(fails, willfail)

puts " "
puts "---Problem 3---"
puts secondSmallest(nums)

puts " "
puts "---Problem 4---"
puts "Problem 4: Iterative"
puts iterativeMap(iterMap)
puts "Problem 4: Recursive"
puts recursiveMap(recMap, (recMap.count()-1))
