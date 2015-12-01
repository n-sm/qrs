;; http://www.emacswiki.org/emacs/MacroBasics
(defmacro ++ (x)
  `(setq ,x (1+ ,x)))

;; which means:
 (defmacro ++2 (x)
      (list 'setq x (list '1+ x)))

(macroexpand '(++ foo))
(setq foo (1+ foo))
