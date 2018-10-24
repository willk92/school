# William Kelley
# CS417-OOP
# ruby1.rb

def makeMcNuggetNumbers(nums)
  mcNuggets = []
  counter = 0
  for i in 0..nums.count()-1
    for j in 0..nums.count()-1
      mcNuggets[counter] = nums[i] + nums[j]
      counter = counter + 1
    end
  end
  # Have to put regular mcNugget numbers back into array
  mcNuggets = mcNuggets + nums
  # Pull out duplicate numbers
  mcNuggets = mcNuggets.uniq
  mcNuggets = mcNuggets.sort
  return mcNuggets
end

def removeMcNuggets(nuggets, value)
  localArray = []
  returnArray = []
  for i in 1..value
    localArray.push(i)
  end
  returnArray = localArray - nuggets
  puts returnArray
end

baseMcNuggets = 4, 6, 9, 20
mcNuggets = []

mcNuggets = makeMcNuggetNumbers(baseMcNuggets)

puts "Enter a maximum number"
val = gets.chomp
val = val.to_i

removeMcNuggets(mcNuggets,val)
