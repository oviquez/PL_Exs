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