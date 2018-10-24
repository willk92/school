# William Kelley
# CS417-OOP
# ruby3.rb

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

squaresOfTwo = []
getTeams = 0

for i in 1..10
  squaresOfTwo.push(2**i)
end

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
