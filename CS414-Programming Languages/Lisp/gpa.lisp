;single list of 1 grade to test small f(x)
(setq grade `(Bio 3 3.0))

;gets GPA of a single class
(defun prod (l)
  (* (cadr l) (caddr l))
)

;doesnt work as is
(defun totpts (l)
  (cond (null l) nil)
  ((+ prod (car l))(totpts(cdr l)))
)

;gets gpa of 1 student
(defun getgpa (l)
  (/ (totpts l)(sumhr l))
)

;need a (sumhr l) routine

;idk what this f(x) is supposed to do but he gave it to us
(defun combine(l)
  (cons (car l)(getgpa l))
)

;f(x) to break list down
;f(x) to build sorted list

(print (prod grade))
;(print (totpts grade))

