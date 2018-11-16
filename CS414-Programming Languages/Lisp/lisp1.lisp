;Setup List and Functions to Act on Lisp

;set up a list
(setq l '(5 -7 12 -9 13 8 -8 2 -10 21))

;length of list
(defun len (list)
  (cond ((null list) 0)
  ;Increment counter recursively until end of list
  ((1+ (len (cdr list))))
  )
)



;sum of list
(defun sum (list)
  (cond ((null list) 0)
  ;Add first element of list
  ;Recursively call sum on the rest of the list
  ((+ (car list) (sum (cdr list))))
  )
)

;average of list
(defun avg (list)
  (float (/ (sum list)(len list)))
)

;extract a list of the positive numbers
(defun pos (list)
  (cond ((null list)())
    ((>=  (car list) 0)		          ;Positive number?
     (cons (car list)		            ;Add item to result of
	   (pos (cdr list))))             ;Recursion on rest of list
    ((< (car list) 0)               ;Negative numer?
     (pos (cdr list))
     ))
)

;sum of positive numbers in list
(defun possum (list)
  (sum (pos list))
)

;average of positive numbers in list
(defun posavg (list)
  (avg (pos list))
)

;sum of negatives numbers in list
(defun negsum (list)
  (- (sum list)(possum list))
)

;average of negative numbers in list
(defun negavg (list)
  (float (/ (negsum list)(- (len list)(len (pos list)))))
)

;Using Functions on List

;print the list
(print "Items within the list")
(print l)

;print result of len(list)
(print "Length of List")
(print (len l))

;print result of sum(list)
(print "Sum of List")
(print (sum l))

;print result of avg(list)
(print "Average of List")
(print (avg l))

;print list of positives
(print "List of Positives")
(print (pos l))

;print sum of positive numbers
(print "Sum of Positive Numbers")
(print (possum l))

;print average of positive numbers
(print "Average of Positive Numbers")
(print (posavg l))

;print sum of negative numbers
(print "Sum of Negative Numbers")
(print (negsum l))

;print number of negatives
(print "Average of Negative Numbers")
(print (negavg l))