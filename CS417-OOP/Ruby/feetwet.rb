# William Kelley
# CS417-OOP
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

puts occurences(nums,num)
puts occurences(strings, string)
puts occurences(characters, character)

puts numSmaller(nums,num)
puts numSmaller(fails, willfail)

puts secondSmallest(nums)

iterativeMap(iterMap)
recursiveMap(recMap, (recMap.count()-1))
