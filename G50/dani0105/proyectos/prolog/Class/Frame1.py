import tkinter as tk                
from tkinter import font  as tkfont 
from tkinter import *
import random
from pyswip import Prolog
from Class.Block import Block

class Frame1(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.controller = controller
        self.canvas = None
        self.prolog = Prolog()
        self.matrix = []
        self.blockSize = 30
        self.groupButtons = []
        self.manual = True
        self.initObjects()
        self.prolog.consult("code.pl")

    def initObjects(self):
        label = tk.Label(self, text = "Tamaño de N ")
        label.grid(row=0,column=0)
        size = StringVar()
        self.entry1 = tk.Entry(self, textvariable=size)
        self.entry1.grid(row=0,column=1)
        button1 = tk.Button(self, text="Generar", command=lambda: self.setMatrixSize())
        button1.grid(row=0,column=3)
        button2 = tk.Button(self, text="Rellenar Auto", command=lambda: self.autoFill())
        button2.grid(row=0,column=4)
        self.Button1Text = tk.StringVar()

        self.Button1Text.set("Marcando Casilla")
        button3 = tk.Button(self, textvariable=self.Button1Text, command=lambda:self.switchMode())
        button3.grid(row=0,column=5)

    def switchMode(self):
        if self.manual:
            self.Button1Text.set("Seleccionando Grupo")
        else:
            self.Button1Text.set("Marcando Casilla")
        self.manual = not self.manual

    def destroyGroupButtons(self):
        for button in self.groupButtons:
            button.destroy()
        self.groupButtons = []

    def autoFill(self):
        self.clearMarks()
        self.destroyGroupButtons()
        for x in range(int(self.size*self.size/2)):
            x = random.randint(0,self.size-1)
            y = random.randint(0,self.size-1)
            temp = self.matrix[y][x]
            temp.changeFlag(self.canvas)
            if temp.flag:
                neighboards = self.blockNeighboards(x,y)
                self.insertBlock(neighboards,temp.id)
            else:
                self.deleteBlock(temp.id)

    def getNeighbord(self,x,y):
        if x >=0 and x < self.size and y>=0 and y< self.size:
            temp = self.matrix[y][x]
            if temp.flag:
                return temp.id
        return False

    def blockNeighboards(self,x,y):
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
        return links

    def insertBlock(self,neighboards, id):
        list(self.prolog.query("insert("+str(id)+","+str(neighboards)+")"))

    def deleteBlock(self,id):
        list(self.prolog.query("delete("+str(id)+")"))
    
    def deleteAllBlocks(self):
        list(self.prolog.query("delete_all()"))
    
    def getGroup(self,id):
        group = list(self.prolog.query("find_group("+str(id)+",Result)"))
        if len(group) >=1:
            return group[0]['Result']

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

    def setMatrixSize(self):
        text = self.entry1.get()
        try:
            self.size = int(text)
            if self.size < 20:
                self.generateMatrix()
        except:
            pass

    def generateMatrix(self):
        width = self.size*self.blockSize
        self.destroyGroupButtons()
        self.deleteAllBlocks()
        if self.canvas is not None:
            self.canvas.destroy()
        self.canvas = tk.Canvas(self,width = width,height=width,bg="black")
        self.canvas.bind("<Button 1>",self.onClick)
        self.canvas.grid(row=1,columnspan = 5)
        button2 = tk.Button(self, text="Buscar Grupos", command=lambda: self.getAllGroups())
        button2.grid(row=2,column=2) 
        self.matrix = [[]]
        p =0
        y = x = 0
        for z in range(self.size*self.size):
            temp = Block(z,x,y,30,'red')
            temp.draw(self.canvas)
            self.matrix[p].append(temp)
            x = x + 30
            if( x >= width):
                y = y + 30
                self.matrix.append([])
                p = p+1
                x=0

    def clearMarks(self):
        for x in self.matrix:
            for dot in x:
                if dot.flag:
                    dot.desmark(self.canvas)

    def markGroup(self,groupSize):
        self.clearMarks()
        for group in self.groups:
            if(len(group) == groupSize):
                for id in group:
                    row = int(id/self.size) 
                    for dot in self.matrix[row]:
                        if dot.id == id and dot.flag:
                            dot.mark(self.canvas)

    def onClick(self,event):
        x = int(event.x /30)
        y = int(event.y /30)
        block = self.matrix[y][x]
        if self.manual:
            block.changeFlag(self.canvas)
            if block.flag:
                neighboards = self.blockNeighboards(x,y)
                self.insertBlock(neighboards,block.id)
            else:
                self.deleteBlock(block.id)
        else:
            self.clearMarks()
            group = self.getGroup(block.id)
            for id in group:
                row = int(id/self.size) 
                for dot in self.matrix[row]:
                    if dot.id == id and dot.flag:
                        dot.mark(self.canvas)