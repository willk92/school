(setq l '((name Seymore) (eng 3 4.0) (mat 3 3.0) (his 3 4.0) (bio 3 2.0) (biol 1 4.0)))

(defun prod (l)
  ( * (cadar l) (caddar l ))
)

(defun totpt (l)
  (cond ((null l) 0)
    (T (+  (prod l)(totpt (cdr l)) ))
  )
)

(defun gethr (l)
  (cadadr l)
)

(defun smhr (l)
  (cond ((null l) 0)
    (T (+  (cadar l)(smhr (cdr l)) ))
  )
)

(defun len (l)
(cond ((null l) 0)
		(T (+ 1(len (cdr l))))
  )
)

(defun addp(l)
  (cond ((null l) 0 )
    (T (+ (cadar l )(addp(cdr l)))); > closes at this line positive then add it
  )
) ; if its neg ignore it and get next one

(defun getgpa (l)
  (cond ((null l) 0)
    (T (/ (totpt (cdr l))(smhr (cdr l))))
  )
)

;(print (smhr(cdr l)))


;(trace getgpa)
(print (getgpa l))