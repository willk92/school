# William Kelley
# CS417-OOP
# Ruby Assignment
# Assignment05-Part 2
# rubyassignmentpt2.rb

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

# If num mod 3 == 0 then you simply divide it by 3 since you can flip
# the light in the middle of each group of 3 to achieve desired result
def multipleOfThrees(num)
  puts num/3
end

def lightsMod2(num)
  puts num
end

def lightsMod1(num)
  puts num
end

def GamesForFirst(teams)
  return teams-1
end

# Add 2 games to GamesForFirst() since you take the loser from
# the winning game and have them play the winner of the two losers
# from the previous bracket
def GamesForSecond(teams)
  return teams+1
end

def AreGamesSquare(teams, arrayVals)
  return arrayVals.include? teams
end

# Problem 1

baseMcNuggets = 4, 6, 9, 20
mcNuggets = []

mcNuggets = makeMcNuggetNumbers(baseMcNuggets)

puts "---Problem 1---"
puts " "
puts "Enter a maximum number for McNuggets"
val = gets.chomp
val = val.to_i

removeMcNuggets(mcNuggets,val)

# Problem 2

lights = 0

puts "---Problem 2---"
puts " "
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
end

# Problem 3

squaresOfTwo = []
getTeams = 0

for i in 1..10
  squaresOfTwo.push(2**i)
end

puts "---Problem 3---"
puts " "
puts "Number of teams must be one of the following numbers"
puts squaresOfTwo

puts "How many teams will be playing?"
getTeams = gets.chomp
getTeams = getTeams.to_i

if(AreGamesSquare(getTeams, squaresOfTwo) == true)
  puts "Games Played to Find First Place"
  puts GamesForFirst(getTeams)
  puts "Rounds Played to Reach First Place"
  puts squaresOfTwo.index(getTeams)+1
  puts "Games Played to Find Second Place"
  puts GamesForSecond(getTeams)
else
  puts "Number of Games Entered are not Valid"
end
