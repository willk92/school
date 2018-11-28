;William Kelley
;map.lisp - How many colors to color map
;CS414-Programming Languages
;Nov 20, 2018

(setq colors '(blue yellow red green orange))
(setq elementlist
  '(
    (a c e f)
		(b c)
    (c a b d e f h)
    (d c e h i)
    (e a c d i j k)
    (f a c g h o q)
    (g f o p q)
    (h c d f i k m n o)
    (i d e h j k)
    (j e i k)
    (k e h i j l m)
    (l k m p q)
    (m h k l n p)
    (n h m o p)
    (o f g h n p)
    (p g l m n o q)
    (q f g l p)
	)
)

(defun checklist (element l)
	(cond
		((null l) nil)
		((eq element (car l)))
		(t (checklist element (cdr l)))
	)
)

;compares neighbor color list with good list
(defun colorstouse(colorlist neighborcolorlist)
	(cond
		((null colorlist) ())
		((checklist (car colorlist) neighborcolorlist) (colorstouse (cdr colorlist) neighborcolorlist))
		(t (cons (car colorlist) (colorstouse (cdr colorlist) neighborcolorlist)))
	)
)

;build/print colored elements
(defun colorelement(colornode neighborlist colorlist usedcolors)
	(cond
		((null (get (car neighborlist) 'color)) (setf (get colornode 'color) (car (colorstouse colorlist usedcolors) ))
               (format t  "~A: ~A~%" colornode (get colornode 'color))  )

		(t (colorelement colornode (cdr neighborlist) colorlist (cons (get (car neighborlist) 'color) usedcolors)))
	)
)



;evaluates list to assign colors
(defun evaluatelist(statelist colorlist)
	(cond
		((null statelist) nil)
		(t (colorelement (caar statelist) (cdar statelist) colorlist () ) (evaluatelist (cdr statelist) colorlist))
	)
)

(dribble "/Users/williamkelley/Documents/GitHub/school/CS414-Programming Languages/Lisp/output_map.txt")

(evaluatelist elementlist colors)

(dribble)