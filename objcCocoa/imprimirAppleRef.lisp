(defun sacar-see-alsos  () (interactive)
       (replace-regexp
	"<div class=\"see-alsos\">\\(.\\|\n\\)*?</div>"
	""
	nil (point) (point-max)))

(defun caracteres-no-reconocidos () (interactive)
       (reemplazos-string
	(list (eval (char-to-string 8212)))
	'("-")))



(defun insertar-style () (interactive)
       (replace-string
	"</header>"
	"</header>
    <style>
      body, a, h1, h2, h3 {
      font-family: "Lucida Sans Unicode", sans-serif;
      }
    </style>
" nil 0 (point-max)))

(defun insert-eol-get () (interactive)
       (replace-string
	"{ get }
"
	"{ get }<br/>
" nil 0 (point-max)))

(defun insert-eol-objcode () (interactive)
       (replace-string
	",</span>
"
	",<br/></span>
" nil 0 (point-max)))

