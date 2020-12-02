import tkinter as tk     
from Class.Frame1 import Frame1

class Program(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)
        frame = Frame1(parent=container,controller=self)
        frame.grid(row=0, column=0, sticky="nsew")
        frame.tkraise()