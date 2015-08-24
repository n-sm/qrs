#!/usr/bin/env python
import Tkinter as tk

class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createWidgets()

    def createWidgets(self):
        self.label = tk.Label(self, text="Una Label.\nApretar el boton para salir.")
        self.label.grid()
        self.quitButton = tk.Button(self, text='Quit',
                                    command=self.quit)
        self.quitButton.grid(column=3, row=2)

        self.label2 = tk.Label(self, text="Otra label.")
        self.label2.grid(column=3, row=4)

        
app = Application()
app.master.title('Sample application')
app.mainloop()
