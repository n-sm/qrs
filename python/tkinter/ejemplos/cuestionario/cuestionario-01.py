#/usr/bin/env python

# John Grayson, 4.12

try:
    import Tkinter as tk
except ImportError:
    import tkinter as tk

class GUI():
    def __init__(self, preguntas):
        self.root = tk.Tk()
#        self.frame = tk.Frame(self.root, width=1000, height=1000).pack()
        self.frame = tk.Frame(self.root).pack()

        with open(preguntas) as f:
            for line in f:
                line = line.rstrip('\n')
                item(self.frame, line).pack()

        
class item(tk.Frame):
    def __init__(self, parent, pregunta):
#        self.pregunta = "La pregunta iría acá. El string de la misma se lee de un archivo."
        self.var = tk.IntVar()
        self.opciones = [('Opción 1', 1), ('Opción 2', 2),
                         ('Opción 3', 3), ('Opción 4', 4)]

        tk.Frame.__init__(self, parent)

        label = tk.Label(self, text=pregunta).pack()

        for text, value in self.opciones:
            tk.Radiobutton(self, text=text, value=value, variable=self.var).pack(side=tk.LEFT)
#            self.var.set(3)
            

GUI('preg1').root.mainloop()

        
