# William Kelley
# CS417-OOP
# Crate a Ruby script that defines a funciton secondSmallest(list)
# that takes an array and returns the position of the second smallest element
# in the list. In case the smallest entry occurs more than once, the second
# occurrance of the item would be considered the second smallest entry.
# https://stackoverflow.com/questions/13659696/find-indices-of-elements-that-match-a-given-condition
# https://stackoverflow.com/questions/21566397/finding-the-index-of-second-smallest-number-in-the-list
# feetwet3.rb

def secondSmallest(arr)
  mn = arr.min
  mx = arr.max
  arr.map! { |e| e == mn ? mx : e }
  num = arr.min
  p arr.each_index.select{|i| arr[i] == num}
  var = p[1]
  puts var
  return p
end

nums = 1,2,3,3,1,1,2,3,4,5

puts secondSmallest(nums)
