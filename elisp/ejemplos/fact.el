(defun fact (n)
  (pcase n
    (`0 1)
    (other (* n (fact (1- n))))))
