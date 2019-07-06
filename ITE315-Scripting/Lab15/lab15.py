#!/ usr/bin/python
from Crypto.Hash import SHA512
import sys

def main(argv):
	if len(argv) < 2:
		print("Usage: hashfile .py fname")
		print("fname −> name of file to be hashed")
	else :
		fname = argv [1]
		hasher = SHA512.new()
		with open(fname, 'rb') as aFile:
			buf = aFile.read()
			hasher. update(buf)
		print(hasher.hexdigest())

if __name__ == "__main__":
	main(sys.argv)