(defun one-char-strp (string)
  (if (= (length string) 1 ) t nil))

(defun html-element (arg) 
  "Tagea toda la region seleccionada con ARG."
  (interactive "stag: ")
  (taguear (concat "<" arg ">") (concat "</" arg ">")))
