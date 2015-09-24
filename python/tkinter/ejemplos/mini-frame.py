#/usr/bin/env python

# John Grayson, 4.12

import tkinter as tk

class MyWindow(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)
        label = tk.Label(root, text="Hello, world")
        label.pack()
        label.bind("<1>", self.quit)
    def quit(self):
        sys.exit()

class GUI():
    def __init__(self):
        root = tk.Tk()
        of = [None]*5
        for bdw in range(5):
            of[bdw] = tk.Frame(self.root, borderwidth=0)
            tk.Label(of[bdw], text='borderwidth = %d ' % bdw).pack(side=LEFT)
            ifx = 0
            iff = []
            for relief in \
                [tk.RAISED, tk.SUNKEN, tk.FLAT, tk.RIDGE, tk.GROOVE, tk.SOLID]:
                iff.append(tk.Frame(of[bdw], borderwidth=bdw, relief=relief))
                tk.Label(iff[ifx], text=relief, width=10).pack(side=LEFT)
                iff[ifx].pack(side=LEFT, padx=7-bdw, pady=5+bdw)
                ifx = ifx+1
            of[bdw].pack()

GUI()
#root = tk.Tk()
#MyWindow(root).pack()
#root.mainloop()
