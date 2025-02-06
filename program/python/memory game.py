import tkinter as tk
import time
import random

window = tk.Tk()
window.title('memory game')
dat = []
for i in range(10):
    window.grid_columnconfigure(i, minsize=20)
    window.grid_rowconfigure(i, minsize=20)
for i in range(10):
    dat.append([])
    for j in range(10):
        dat[i].append(tk.Button(window,text="",height=2,width=5))
        dat[i][j].grid(column=i,row=j)

show_number = []
for i in range(10):
    for j in range(10):
        

