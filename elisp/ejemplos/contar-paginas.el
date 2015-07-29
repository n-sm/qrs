;;; Cuenta las páginas a imprimir dado 'lista', que corrseponde
;;; a los intercalos a imprimir. Por ejemplo, para imprimir las
;;; páginas 10 a 20 y 35 a 46, lista tiene que ser:
;;; (10 20 35 46)

(defun contar-pags (lista)
  (if (null lista)
      0
    (if (null (cdr lista))
	1
      (if (null (cddr lista))
	  (- (cadr lista) (car lista))
	(+ (foo (subseq lista 0 2))
	   (foo (cddr lista)))))))

(defun str2list (str)
  (insert (setq retstr (replace-regexp-in-string "-" " " str)
		retstr (replace-regexp-in-string "," " " ret)
		retstr (concat "(" retstr ")"))))

