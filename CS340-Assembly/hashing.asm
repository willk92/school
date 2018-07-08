; Read sentence to hash
; Read in hash
; Write out read sentence
; Hash sentence
; Write out hashed sentence
; Unhash sentence
; Write out unhashed sentence

; Grab next sentence
; Grab next hash
; Repeat steps from above until read in is complete

cin sentence to array
cin hash to array
cout sentence
while(sentence has not reached return character)
{
  ary[i] = ary[i] + bry[k] ; hash it
  if (bry[k] = return character) ; reset hashing array back to first index
    {
      bry[k] = 0
    }
}
cout sentence_hash
{
  ary[i] = ary[i] - bry[k]  ; unhash it
  if (bry[k] = return character) ; reset hashing array back to first index
    {
      bry[k] = 0
    }
}
cout sentence_unhash

infile next_sentence

repeat cout sentence, while(hash), cout sentence_hash, while(unhash), cout sentence_unhash