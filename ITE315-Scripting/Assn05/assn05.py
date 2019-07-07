#!/usr/bin/python

# William Kelley
# ITE315-Assignment 05
# July 5, 2019

# Problem Number 2 is not in the "easy" category in my opinion. Working on a better implementation
# of it, I just wanted to make sure I got something decent to submit.

# Sources:
# https://teamtreehouse.com/community/counting-words-in-a-string-using-a-dictionary-python-collection-challenge
#

import calendar

#Problem 1
def wordCounter(countMe):
  print(countMe)
  countMe = countMe.lower().split()
  countDict = {}
  for i in countMe:
    if i in countDict:
      countDict[i] += 1
    else:
      countDict[i] = 1
  return countDict

#Problem 2
def calendarPrint(month):
  return (calendar.month(2019, int(month, 10)))

#Problem 3
def countString(string):
  return len(string)


def main():
  print(wordCounter("hello world how are you today hello today"))
  month=input("Enter a month number:\n")
  print(calendarPrint(month))
  print(countString("hello this is something about strings"))



if __name__ == "__main__":
  main()