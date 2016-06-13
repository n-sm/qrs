(defun a_ (n)
  (cond
   ((eq 1 n) 2)
   ((eq 2 n) 8)
   (t (+ (* (/ (1+ n) 2) (a_ (- n 2)))
	 (* (+ n 2) (a_ (1- n)))))))

  
(defun a (n)
  (pcase n
    (`1 2)
    (`2 8)
    (other (+ (* (/ (1+ n) 2) (a_ (- n 2)))
	      (* (+ n 2) (a_ (1- n))))))) 
