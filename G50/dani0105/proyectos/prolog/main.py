import tkinter as tk                
from tkinter import font  as tkfont 
from tkinter import *
import random
from pyswip import Prolog

class Program(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)
        frame = MainFrame(parent=container,controller=self)
        frame.grid(row=0, column=0, sticky="nsew")
        frame.tkraise()

class MainFrame(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.controller = controller
        label1 = tk.Label(self, text = "Tamaño de N ")
        label1.grid(row=0,column=0)
        self.canvas = None
        self.prolog = Prolog()
        self.prolog.consult("code.pl")
        self.matrix = []
        self.groupButtons = []
        self.manual = True
        size = StringVar()
        self.entry1 = tk.Entry(self, textvariable=size)
        self.entry1.grid(row=0,column=1)

        button1 = tk.Button(self, text="Generar", command=lambda: self.getSize())
        button1.grid(row=0,column=3)

        button2 = tk.Button(self, text="Rellenar Auto", command=lambda: self.fill())
        button2.grid(row=0,column=4)

        self.Button1Text = tk.StringVar()
        self.Button1Text.set("Marcando Casilla")
        button3 = tk.Button(self, textvariable=self.Button1Text, command=lambda:self.changeMode())
        button3.grid(row=0,column=5)
    
    def changeMode(self):
        if self.manual:
            self.Button1Text.set("Seleccionando Grupo")
        else:
            self.Button1Text.set("Marcando Casilla")
        self.manual = not self.manual

    def fill(self):
        self.destroyGroupButtons()
        for x in range(int(self.size*self.size/2)):
            x = random.randint(0,self.size-1)
            y = random.randint(0,self.size-1)
            temp = self.matrix[y][x]
            temp.changeFlag(self.canvas)
            if temp.flag:
                self.getNeighbords(x,y,temp)
            else:
                list(self.prolog.query("delete("+str(temp.id)+")"))

    def getSize(self):
        text = self.entry1.get()
        try:
            self.size = int(text)
            if self.size < 20:
                self.generateMatrix(self.size)
        except:
            pass
    
    def generateMatrix(self,size):
        width = size*30
        list(self.prolog.query("delete_all()"))
        self.destroyGroupButtons()
        if self.canvas is not None:
            self.canvas.destroy()
        self.canvas = tk.Canvas(self,width = width,height=width,bg="black")
        self.canvas.bind("<Button 1>",self.getBlock)
        self.canvas.grid(row=1,columnspan = 5)
        button2 = tk.Button(self, text="Buscar Grupos", command=lambda: self.getAllGroups())
        button2.grid(row=2,column=2) 
        self.matrix = [[]]
        p =0
        y = x = 0
        for z in range(size*size):
            temp = Block(z,x,y,30,'red')
            temp.draw(self.canvas)
            self.matrix[p].append(temp)
            x = x + 30
            if( x >= width):
                y = y + 30
                self.matrix.append([])
                p = p+1
                x=0
    
    def getAllGroups(self):
        self.destroyGroupButtons()
        groupNum = []
        self.groups = list(self.prolog.query("find_all_groups(Result)"))[0]['Result']
        x=3
        y=0
        for group in self.groups:
            size = len(group)
            if not( size in groupNum):
                groupNum.append(size)

                button2 = tk.Button(self, text="grupos de "+str(size), command=lambda size=size: self.markGroup(size))
                button2.grid(row=x,column=y)

                self.groupButtons.append(button2)
                y +=1
                if(y > 4):
                    x += 1
                    y=0
    def destroyGroupButtons(self):
        for button in self.groupButtons:
            button.destroy()
        self.groupButtons = []

    def markGroup(self,size):
        self.clearMarks()
        print(size)
        for group in self.groups:
            if(len(group) == size):
                for id in group:
                    row = int(id/self.size) 
                    for dot in self.matrix[row]:
                        if dot.id == id and dot.flag:
                            dot.mark(self.canvas)


    def getBlock(self,event):
        x = int(event.x /30)
        y = int(event.y /30)
        temp = self.matrix[y][x]
        if(self.manual):
            temp.changeFlag(self.canvas)
            if temp.flag:
                self.getNeighbords(x,y,temp)
            else:
                list(self.prolog.query("delete("+str(temp.id)+")"))
        else:
            self.clearMarks()
            group = list(self.prolog.query("find_group("+str(temp.id)+",Result)"))
            
            if len(group) >=1:
                group = group[0]['Result']
                for id in group:
                    row = int(id/self.size) 
                    for dot in self.matrix[row]:
                        if dot.id == id and dot.flag:
                            dot.mark(self.canvas)
    
    def getNeighbords(self,x,y,temp):
        links =[]
        result = self.getNeighbord(x,y-1)
        if result:
            links.append(result)
        
        result = self.getNeighbord(x,y+1)
        if result:
            links.append(result)

        result = self.getNeighbord(x-1,y)
        if result:
            links.append(result)
        
        result = self.getNeighbord(x+1,y)
        if result:
            links.append(result)
        list(self.prolog.query("insert("+str(temp.id)+","+str(links)+")"))

    def getNeighbord(self,x,y):
        if x >=0 and x < self.size and y>=0 and y< self.size:
            temp = self.matrix[y][x]
            if temp.flag:
                return temp.id
        return False
    
    def clearMarks(self):
        for x in self.matrix:
            for dot in x:
                if dot.flag:
                    dot.desmark(self.canvas)


class Block:
    def __init__(self,id,x,y,size,color):
        self.id = id
        self.x = x
        self.y = y
        self.size = size
        self.color = color
        self.shape = None
        self.flag = False
        self.markFlag = False
    
    def draw(self,canvas):
        self.shape = canvas.create_rectangle(self.x, self.y, self.x+self.size, self.y+self.size, fill="white")

    def changeFlag(self,canvas):
        if(self.flag):
            canvas.itemconfigure(self.shape,fill='white')
        else:
            canvas.itemconfigure(self.shape,fill='black')
        self.flag = not self.flag
    
    def mark(self,canvas):
        self.markFlag = True
        canvas.itemconfigure(self.shape,fill='Orange')
    
    def desmark(self,canvas):
        self.markFlag = False
        canvas.itemconfigure(self.shape,fill='black')


app = Program()
app.mainloop()