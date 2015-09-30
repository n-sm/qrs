#/usr/bin/env python

# John Grayson, 4.12

try:
    import Tkinter as tk
except ImportError:
    import tkinter as tk

class GUI():
    def __init__(self):
        self.root = tk.Tk()
        self.frame = tk.Frame(self.root, width=1000).pack()
        for i in range(2):
            item(self.frame).pack()

        
class item(tk.Frame):
    def __init__(self, parent):
        self.pregunta = "La pregunta iría acá. El string de la misma se lee de un archivo."
        self.var = tk.IntVar()
        self.opciones = [('Opción 1', 1), ('Opción 2', 2),
                         ('Opción 3', 3), ('Opción 4', 4)]

        tk.Frame.__init__(self, parent)

        label = tk.Label(self, text=self.pregunta).pack()

        for text, value in self.opciones:
            tk.Radiobutton(self, text=text, value=value, variable=self.var).pack(side=tk.LEFT)
            self.var.set(3)
            


##root = tk.Tk()
##frame = tk.Frame(root, width=1000).pack()
##item(frame).pack()
##item(frame).pack()
##
##
##root.mainloop()

GUI().root.mainloop()
