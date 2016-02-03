
(defun my-view-source (url)
  (interactive "MURL: ")
  (switch-to-buffer (url-retrieve url (lambda (_)))))

;;; más simple
(defun view-source2 (url)
  (interactive "URL: ")
  (switch-to-buffer
   (url-retrieve-synchronously url)))
