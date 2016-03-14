;; http://www.emacswiki.org/emacs/MacroBasics
(defmacro ++ (x)
  `(setq ,x (1+ ,x)))

;; which means:
 (defmacro ++2 (x)
      (list 'setq x (list '1+ x)))

;; macroexpand shows the resulting expresion
(macroexpand '(++ foo))
(setq foo (1+ foo))


(defmacro test (a b)
  `(+ ,a ,b))

(test 1 2)

    



