;;; En este ejemplo se muestra el uso de:
;;; PATTERN1\\(.\\|\n\\)*?PATTERN2
;;; para denotar "cualquier caracter, incluso newline, entre
;;; PATTERN1 y PATTERN2.

;;; la func foo sirve para sacar :

"
User Services Working Group                                     [Page 2]
 
RFC 1594            FYI Q/A - for New Internet Users          March 1994
"

;; y foo2 para sacar:
"
Plzak, et al.                Informational                      [Page 1]
 
RFC 2664            FYI Q/A - for New Internet Users         August 1999
"
(defun foo () (interactive)
       (replace-regexp "User .*\[Page [0-9]?\].*\\(.\\|\n\\)*? March 1994.*"
		       ""
		       nil (point) (point-max)))



(defun foo2 () (interactive)
       (replace-regexp "Plzak, .*\[Page [0-9]?\].*\\(.\\|\n\\)*? August 1999.*"
		       ""
		       nil (point) (point-max)))

