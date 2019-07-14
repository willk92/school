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

def mutateDna(dnaList):
  for _ in range(100):
    #get a random sequence
    index = random.randint(0, 999)
    #assign it as a list to be able to edit one gene
    mutate = list(dnaList[index])
    #insert the mutated gene
    mutate = generateString(3)
    #convert back to a string
    dnaList[index] = ''.join(mutate)
  return dnaList

def generateString(N, alphabet=list('ATGC')):
  dnaList = [random.choice(alphabet) for i in range(N)]
  dnaList = ''.join(dnaList)
  return dnaList

# def findConsensus(freqMatrix):
#   consensus = ''
#   dnaLength = len(freqMatrix['A'])

#   for i in range(dnaLength):
#     maxFreq = -1
#     maxFreqBase = None
#     for base in 'ATGC':
#       l = freqMatrix[base]
#       if l[i] > maxFreq:
#         maxFreq = freqMatrix[base][i]
#         maxFreqBase = base
#       elif l[i] == maxFreq:
#         maxFreqBase = '-'
#     consensus += maxFreqBase
#   return consensus

def main():
  listDna=list()
  for _ in range(1000):
    listDna.append((generateString(3)))
  print("Random 1000 bases")
  print(frequencyTable(listDna))
  print("Mutated 1000 bases")
  print(frequencyTable(mutateDna(listDna)))

if __name__ == '__main__':
  main()