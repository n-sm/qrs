import Tinter as tk

def quit():
    sys.exit()
root = tk.Tk()
label = tk.Label(root, text="Hello, world")
label.pack()
label.bind("<1>", quit)
root.mainloop()
