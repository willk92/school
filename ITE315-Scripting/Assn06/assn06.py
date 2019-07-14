#!/usr/bin/python

import random

def frequencyTable(dnaList):
  n = max([len(dna) for dna in dnaList])
  frequency_matrix = {
    'A': [0]*n,
    'C': [0]*n,
    'G': [0]*n,
    'T': [0]*n
  }
  for dna in dnaList:
    for index, base in enumerate(dna):
      frequency_matrix[base][index] += 1

  return frequency_matrix

def mutateSingleGene(dnaList, size=100):
  for _ in range(size):
    #get a random sequence
    index = random.randint(0, (size-1))
    #assign it as a list to be able to edit one gene
    mutate = list(dnaList[index])
    #insert the mutated gene
    mutate[random.randint(0, 2)] = random.choice('ATGC')
    #convert back to a string
    dnaList[index] = ''.join(mutate)
  return dnaList

def generateString(N, alphabet=list('ATGC')):
  dnaList = [random.choice(alphabet) for i in range(N)]
  dnaList = ''.join(dnaList)
  return dnaList

def getBusInfo(fname):
  schedule = []
  file = open(fname, "r")
  cities = file.readline()
  cities = cities.rstrip()
  cities = cities.split(":")
  del cities[0]
  schedule.append(cities)
  for line in file:
    line = line.rstrip()
    singleLine = line.split(":")
    del singleLine[0]
    schedule_row = []
    for i in range(len(singleLine)):
      schedule_row.append(singleLine[i])
    schedule.append(schedule_row)
  for i in range(len(schedule)):
    for j in range(len(schedule[i])):
      schedule[i][j] = schedule[i][j].strip()
  return schedule

def printCitySchedule():
  busFile = "samplesched.txt"
  schedule = getBusInfo(busFile)
  for i in range(len(schedule[0])):
    print(schedule[0][i], end="")
    for j in range(len(schedule)):
      if j > 0:
        print(":", end = "")
        print(schedule[j][i], end = "")
    print("")

def main():
  #Problem 1
  # listDna = list()
  # sizeRange = 1000
  # for _ in range(sizeRange):
  #   listDna.append((generateString(3)))
  # print("Random %d bases" % (sizeRange))
  # print(frequencyTable(listDna))
  # print("Mutated %d bases" % (sizeRange))
  # print(frequencyTable(mutateSingleGene(listDna, sizeRange)))

  #Problem 2
  printCitySchedule()


if __name__ == '__main__':
  main()