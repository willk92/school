;William Kelley
;CS414-Programming Languages
;Lisp Workout(Numero Dos)

;Setup a list "l" to perform operations on
(setq l '(5 7 (12 9) 13 (8 8) 2 10 21))

;Return the position of an item within a list
(defun atomlocation (letter list)
      (cond
            ((atom list) nil)
            ((equal letter (car list)) 0)
            ((atomlocation letter (cdr list)) (+ 1 (atomlocation letter (cdr list))))
      )
)


;Prints elemnt at specific location(operates similar to a C++ array)
; - [0] index being the first location in array
;Prints NIL if at end of list
(defun loc (n list)
      (cond ((= n 0) (car list))
             (t (loc (- n 1)(cdr list)))
      )
)

;Combine two sorted lists
(defun mergesort(a b)
      (cond
            ((null a) b)
            ((null b) a)
            ((<= (car a) (car b))
            (cons (car a) (mergesort (cdr a) b))
            )
            (t (cons (car b) (mergesort a (cdr b))))
      )
)

;Merge infinite lists into one
(defun flatten (list)
      (cond ((null list) nil)
            ((atom (car list)) (cons (car list) (flatten (cdr list))))
            (t (append (flatten (car list)) (flatten (cdr list))))
      )
)

;Reverse a list
(defun reverselist (list)
      (cond ((null list) '())
            (t (append (reverselist (cdr list)) (list (car list))))
      )
)

;Helper for atom counter
(defun len (list)
  (cond ((null list) 0)
  ;Increment counter recursively until end of list
  ((1+ (len (cdr list))))
  )
)

;Count number of atoms in a list
(defun atomcounter (list)
      (len (flatten list))
)

(defun removenth (index list)
    (if (and list (< 0 index))
        (cons (car list) (removenth (- index 1) (cdr list)))
        (cdr list)
    )
)

(dribble "/Users/williamkelley/Documents/GitHub/school/CS414-Programming Languages/Lisp/output_lisp2.txt")

;(1)Show the index of an item in a list
(format t "Display Index of an Item if it is within the list")
(format t "~%Location of element a")
(print (atomlocation `a `(a b c d e f)))
(format t "~%Location of element e")
(print (atomlocation `e `(a b c d e f)))
(format t "~%Location of element c")
(print (atomlocation `c `(a b c d e f)))
(format t "~%Location of element z")
(print (atomlocation `z `(a b c d e f)))

;(2)Display a specific location of an element(list or atom) in a list
(format t "~%~%Display item(n) within list(l)~%")
(format t "~%Location 0 in List l")
(print (loc 0 l))
(format t "~%Location 1 in List l")
(print (loc 1 l))
(format t "~%Location 4 in List l(sub-list)")
(print (loc 4 l))

;(3)Merge and Sort
(format t "~%~%Merge and order two lists")
(print (mergesort '(1 3)'(2 4 6)))
(print (mergesort '(1 3 5 6 7 8 9 10 14 17)'(1 4 4 6 7 8 78 99 100 123)))
(print (mergesort '(1 2 3 4 5 7 8 9 13 16 18 22)'(4 6 9 88 99 100 101 102 112)))

;(4)Merge infinite number of lists
(format t "~%~%Merge infinite lists")
(print (flatten '((1 2 3)(2 3 4)(4 5 6))))
(print (flatten '((5 7 8 9)(2 3 4)(4 5 6)(13 16 18 22)(9 8 1 2 3 5 9)(4 5 6 1 2 3))))

;(5)Flatten a list
(format t "~%~%Flatten a list")
(print (flatten '(1 (2 3) 4 (5 6))))
(print (flatten '(a (b c) (e (f g)))))
(print (flatten '(a (b c) (e (f g))1 (2 3) 4 (5 6))))

;(6)Rotate a list

;(7)Reverse a list
(format t "~%~%Reverse a list")
(print (reverselist '(a b c d e)))
(print (reverselist '(5 4 3 2 1)))
(print (reverselist '(1 a 2 c 4 d 2 a)))

;(8)Counter number of atoms
(format t "~%~%Counter number of atoms in list")
(print (atomcounter '(1 (2 3) 4 (5 6))))
(print (atomcounter '(a (b c) (e (f g))1 (2 3) 4 (5 6))))
(print (atomcounter '((5 7 8 9)(2 3 4)(4 5 6)(13 16 18 22)(9 8 1 2 3 5 9)(4 5 6 1 2 3))))

;(9)Remove element at index from list
(format t "~%~%Remove Nth element from a list")
(print (removenth 3 '(1 2 3 4)))
(print (removenth 4 '(1 2 3 4)))
(print (removenth 0 '(1 2 3 4)))
(print (removenth 1 '(1 2 3 4)))

(dribble)