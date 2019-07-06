#!/ usr/bin/python
from Crypto.Hash import SHA512
import sys
import os

def hashAFile(fileName):
	if len(fileName) == 0:
		print("Usage: hashfile .py fname")
		print("fname −> name of file to be hashed")
	else:
		fname = fileName
		hasher = SHA512.new()
		with open(fname, 'rb') as readIt:
			buf = readIt.read()
			hasher.update(buf)
		print(hasher.hexdigest())

def getFileList(dirName):
  if len(dirName) == 0:
    listFiles = os.listdir(os.getcwd())
    for f in listFiles:
      print(f)
      hashAFile(f)
  else:
    listFiles = os.listdir("../"+dirName)
    for f in listFiles:
      f = "../"+dirName+"/"+f
      print(f)
      hashAFile(f)

def main():
  direc = input("Enter a directory to hash: \n")
  getFileList(direc)

if __name__ == "__main__":
  main()