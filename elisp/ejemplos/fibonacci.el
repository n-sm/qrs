(defun fib (n)
  (setq n (1- n))
  (do ((i n (- i 1))
	(f1 1 (+ f1 f2))
	(f2 1 f1))
      ((<= i 1) f1 )))

;;; ejemplo.

(let ((r ()))
  (reverse (dolist (n (number-sequence 1 18) r)
	     (setq r (cons (fib n) r)))))

(1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584)

