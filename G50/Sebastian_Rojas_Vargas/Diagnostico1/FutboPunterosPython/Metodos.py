from Jugador import *

inicio = None
ultimo = None

def insertarOrdenado(nombre, numeroCamisa):
    nuevo = Jugador()
    nuevo.set__info(nombre, numeroCamisa)
    global inicio
    global ultimo
    if (inicio == None):
        inicio = ultimo = nuevo
        return True
        
    if ((inicio.numeroCamisa == nuevo.numeroCamisa) | (ultimo.numeroCamisa == nuevo.numeroCamisa)):
        return False
        
    if (nuevo.numeroCamisa < inicio.numeroCamisa):
        nuevo.sig = inicio
        inicio.ant = nuevo
        inicio = nuevo
        return True
        
    if (nuevo.numeroCamisa > ultimo.numeroCamisa):
        ultimo.sig = nuevo
        nuevo.ant = ultimo
        ultimo = nuevo
        return True
    
    aux = inicio
    while (aux != None):
        if (nuevo.numeroCamisa == aux.numeroCamisa):
            return False
        
        if (nuevo.numeroCamisa < aux.numeroCamisa):
            aux.ant.sig = nuevo
            nuevo.ant = aux.ant
            nuevo.sig = aux
            aux.ant = nuevo
            return True
            
        aux = aux.sig
        
    return False

def mostrar():
    aux = inicio
    while (aux != None):
        aux.get__info()
        aux = aux.sig










