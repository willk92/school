#!/usr/bin/python

import sqlite3
dbname = 'seqdata.db'
try:
  conn = sqlite3.connect(dbname)
except:
  print("Unable to open database")

query = 'SELECT * FROM Sequence'
try:
  rowSet = conn.execute(query)
  for row in rowSet:
    seqNum = row[0]
    sequence = row[1]
    print("Sequence %d:\t%s" % (seqNum, sequence))
except:
  print("Error: Unable to access the database")

conn.close()