# William Kelley
# CS417-OOP
# Write two new methods of Array that implement this function:
# a method iteraiveMap that iteratively applies a block to an Array and
# recursiveMap that does the same thing recursively.
# feetwet4.rb

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

iterMap = 1,2,3
recMap = 1,2,3

iterativeMap(iterMap)
recursiveMap(recMap, (recMap.count()-1))
