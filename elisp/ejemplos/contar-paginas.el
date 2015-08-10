;;; Cuenta las páginas a imprimir dado 'lista', que corrseponde
;;; a los intercalos a imprimir. Por ejemplo, para imprimir las
;;; páginas 10 a 20 y 35 a 46, lista tiene que ser:
;;; (10 20 35 46)
;;;
;;; Se muestra además un ejemplo de catch throw.

(defun contar-pags-entre (lista)
  (if (null lista)
      0
    (if (null (cdr lista))
	1
      (if (null (cddr lista))
	  (1+ (- (cadr lista) (car lista)))
	(+ (contar-pags (subseq lista 0 2))
	   (contar-pags (cddr lista)))))))

(defun str2list (str)
  (insert (setq retstr (replace-regexp-in-string "-" " " str)
		retstr (replace-regexp-in-string "," " " retstr)
		retstr (concat "(" retstr ")"))))


;;(defun contar-pags (str) (interactive "s\ Ingrese los intervalos: ")
;;       (contar-pags-entre (str2list str)))



(defun str2list2 (str)
  (setq retstr (replace-regexp-in-string "-" " " str)
		retstr (replace-regexp-in-string "," " " retstr)
		retstr (concat "(" retstr ")")))

(str2list2 "1,4")
(eval "1,4")


(defun prox-match (str char)
  "
Devuelve nul si CHAR no esta en STR.
Si no, devuelve la ubicacion (contando desde cero).
Por ejemplo, el parentesis izquiero es 40.
El espacio es 32."
  (catch 'loop
    (let ((i 0)
	  (strlen (length str)))
      (while (and
	      (< i strlen))
	(if (char-equal char (aref str i))
	    (throw 'loop i))
	(setq i (1+ i))))
    nil))

(defun hay-next-num (str)
  "Esta funcion se puede reacer junto con next-match para que
ambas sean una misma quereciba diferentes argumentos. Otro dia."
  (let ((str (substring str (next-match str 32))))
    (catch 'loop
      (let ((i 0)
	    (strlen (length str)))
	(while (and
		(< i strlen))
	  (if (not (char-equal 32 (aref str i)))
	      (throw 'loop i))
	  (setq i (1+ i))))
      nil)))


;;;; ==========================================================================
(defun avanzar-espacios (str)
  (let ((i 0)
	(strlen (length str)))
    (while (and (< i strlen) (char-equal (aref str i) 32))
      (setq i (1+ i)))
    (substring str  i)))

(defun next-num (str)
  ""
  (let ((str (substring str (next-match (avanzar-espacios str) 32))))
    (catch 'loop
      (let ((i 0)
	    (strlen (length str)))
	(while (and
		(< i strlen))
	  (if (not (char-equal 32 (aref str i)))
	      (throw 'loop (substring str i)))
	  (setq i (1+ i))))
      nil)))

(defun parsear-simple (str)
  "Toma una string de numeros separados por espacios 
y devuelve una lista con esos numeros."
  (if (string= "" str)
      nil
    (if (not (prox-match str 32))
	(list (string-to-number str))
      (cons (string-to-number str)
	    (parsear-simple (next-num str))))))


(defun parsear (str)
  (let* ((retstr (replace-regexp-in-string "^(" "" str))
	 (retstr (replace-regexp-in-string ")$" "" retstr))
	 (retstr (replace-regexp-in-string " +$" "" retstr))
	 (retstr (replace-regexp-in-string "^ +" "" retstr)))
    (if (not (prox-match retstr 40)) ; no hay parentesis (
	(parsear-simple retstr)
    ;;; falta hacer recursion
    nil)))


(defun contar-pags (str)
  "Falta terminar la fun parsear"
  (interactive "s\ Ingrese pags: ")
       (message "%s" (contar-pags-entre (parsear (str2list2 str)))))





