
(defun my-view-source (url)
  (interactive "MURL: ")
  (switch-to-buffer (url-retrieve url (lambda (_)))))

;;; más simple
(defun view-source2 (url)
  (interactive "MURL: ")
  (let ((theUrl (concat "http://" url)))
  (switch-to-buffer
   (url-retrieve-synchronously theUrl))))

(concat "http://" "b")



(defun my-view-source (url)
  (interactive "MURL: ")
  (url-retrieve url (lambda (_))))

;; esto no funcio9na
(setq pag
      (let ((pagina ()))
	(save-excursion
	  (switch-to-buffer
	   (url-retrieve "http://www.google.com" (lambda (_)
						   (setq pagina (buffer-string))))))
	(insert pagina)))

pag




