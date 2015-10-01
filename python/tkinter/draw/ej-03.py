try:
    from Tkinter import *
except ImportError:
    from tkinter import *


root = Tk()
cv = Canvas(root)
cv.create_rectangle(10,10,50,50)
cv.create_rectangle(11,12,53,54)
cv.create_rectangle(0,0,100,100)

cv.pack()
#root.mainloop()

cv.update()
cv.postscript(file="file_name1.ps", colormode='color')

#root.mainloop()
