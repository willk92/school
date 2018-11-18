;William Kelley
;CS414-Programming Languages
;Lisp Workout(Numero Dos)

;Setup a list "l" to perform operations on
(setq l '(5 7 (12 9) 13 (8 8) 2 10 21))

;Prints elemnt at specific location(operates similar to a C++ array)
; - [0] index being the first location in array
;Prints NIL if at end of list
(defun loc (n list)
      (cond ((= n 0) (car list))
             (t (loc (- n 1)(cdr list)))
      )
)

(dribble "/Users/williamkelley/Documents/GitHub/school/CS414-Programming Languages/Lisp/output_lisp2.txt")

;To display (loc n list) works
(format t "Display item(n) within list(l)~%")
(print "Location 0 in List l")
(print (loc 0 l))
(print "Location 1 in List l")
(print (loc 1 l))
(print "Location 4 in List l(sub-list)")
(print (loc 4 l))

(dribble)