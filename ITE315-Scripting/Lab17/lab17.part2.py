#!usr/bin/python

from tkinter import *
import tkinter.messagebox

import sqlite3

top = Tk()
frame = Frame(top)
frame.pack()
label = Label(frame, text="Sequence Mutator", relief=RAISED)
label.pack(side=TOP)

seqListBox = Listbox(frame)

def mutate():
  selectedSeq = seqListBox.curselection()
  if not selectedSeq:
    sequenceString = ''
  else:
    sequenceString = seqListBox.get(selectedSeq)
  print("String to mutate is: " + sequenceString)
  tkinter.messagebox.showinfo("Selected Sequence", sequenceString)

dbname = 'seqdata.db'
try:
  conn = sqlite3.connect(dbname)
except:
  print("Unable to open database")
  tkinter.messagebox.showinfo("Database error", "Unable to open database")

query = 'SELECT * FROM Sequence'

rowSet = conn.execute(query)
for row in rowSet:
  seqNum = row[0]
  sequence = row[1]
  lbcontent = "Sequence %d : %s" % (seqNum, sequence)
  seqListBox.insert(seqNum, sequence)
  print("Sequence %d:\t%s" % (seqNum, sequence))

seqListBox.pack(side=LEFT)

conn.close()

seqListBox.select_clear(0, "end")
seqListBox.selection_set(0)
seqListBox.see(0)
seqListBox.activate(0)
seqListBox.selection_anchor(0)

mutateButton = Button(frame, text="Mutate", fg="black", command=mutate)
mutateButton.pack(side=RIGHT)
top.mainloop()