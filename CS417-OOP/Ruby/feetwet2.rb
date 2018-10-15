# William Kelley
# CS417-OOP
# Create a Ruby script that defines a function numSmaller(list,item)
# that takes an array list of size 1 or larger and integer item as parameters.
# It should return the number of elements in the list that are strictly
# less than item. Again, include sufficient test code for your solution.
# feetwet2.rb

def numSmaller(list, item)
  numElements = list.find_all { |x| x < item }
  return numElements.count()
end

nums = 1,2,3,1,1,2,3,4,5
num = 3

puts numSmaller(nums,num)
