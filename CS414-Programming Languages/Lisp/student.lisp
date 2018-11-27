;William Kelley
;student.lisp
;Produces students gpa and a total average for the class
;CS414-Programming Languages
;Still need to implement sort based on either name or gpa

(setq class '
  (
    ((name Seymore) (eng 3 4.0) (mat 3 3.0) (his 3 4.0) (bio 3 2.0) (biol 1 4.0))
    ((name Ichahbod) (cs 3 3.0) (mat 3 4.0) (spe 2 4.0) (che 3 4.0) (chel 1 3.0) (lit 3 3.0))
    ((name Zackery) (mat 5 3.0) (eng 3 3.0) (jou 2 3.0) (phy 3 3.0) (phyl 1 4.0) (lit 2 4.0))
    ((name Tukerville) (soc 4 3.0) (mus 2 4.0) (jou 3 4.0) (geo 4 4.0) (geol 1 3.0) (eng 3 3.0))
    ((name Simonsays) (css 3 3.0) (ast 3 4.0) (spe 3 4.0) (cs 3 4.0) (spe 2 3.0) (dan 4 4.0))
    ((name Snicker) (eng 3 4.0) (phy 4 4.0) (css 3 2.0) (csl  1 4.0) (ped 2 3.0) (mat 3 3.0))
    ((name Glass) (mat 3 1.0) (eng 3 1.0) (ped 1 1.0) (bio 3 1.0) (biol 1 0.0) (che 3 1.0) (chel 1 1.0))
  )
)

(defun product (l)
  ( * (cadar l) (caddar l ))
)

(defun totalpoints (l)
  (cond ((null l) 0)
    (T (+  (product l)(totalpoints (cdr l)) ))
  )
)

;sum of hours for single student
(defun sumhours (l)
  (cond ((null l) 0)
    (T (+  (cadar l)(sumhours (cdr l)) ))
  )
)

;get len of a list
(defun len (l)
(cond ((null l) 0)
		(T (+ 1(len (cdr l))))
  )
)

;get gpa of single student
(defun getgpa (l)
  (cond ((null l) 0)
    (T (/ (totalpoints (cdr l))(sumhours (cdr l))))
  )
)

(defun sum (l)
  (cond ((null l) 0)
  ;Add second part of first element of list
  ;Recursively call sum on the rest of the list
  ((+ (cdar l) (sum (cdr l))))
  )
)

;produce average for students gpa
(defun average (l)
  (float (/ (sum l)(len l)))
)

;perform necessary operations to build a list of each student name and gpa
(defun eachstudent (l)
  (cond ((null l) nil)
    (T
    (cons (cons (cadaar l)(getgpa (car l)))(eachstudent (cdr l))) ; create list containing student name and gpa
    )
  )
)

(defun printstudent (l)
  (cond ((null l) nil)
    (T
    (print (caar l))
    (print (cdar l))
    (printstudent (cdr l))
    )
  )
)

; Create list from getting student name and gpa
(setq studentgpa (eachstudent class))

;Using functions for gpa

(dribble "/Users/williamkelley/Documents/GitHub/school/CS414-Programming Languages/Lisp/output_student.txt")

(format t "Printing result of running (eachstudent) function")
(print (eachstudent class)) ;showing my eachstudent function works

(format t "~%~%Printing individual students name and gpa")
(printstudent studentgpa)

(format t "~%~%Class Average GPA")
(print (average studentgpa))

(dribble)