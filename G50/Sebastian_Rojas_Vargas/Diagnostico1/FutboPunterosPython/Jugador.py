class Jugador():
    def __init__(self):
        self.nombre = ""
        self.numeroCamisa = 0
        self.ant = None
        self.sig = None
    def set__info(self, nombre, numeroCamisa):
        self.nombre = nombre
        self.numeroCamisa = numeroCamisa
    def get__info(self):
        print (self.nombre, self.numeroCamisa)


