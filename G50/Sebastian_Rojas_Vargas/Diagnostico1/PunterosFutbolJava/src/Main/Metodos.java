/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

/**
 *
 * @author Sebas
 */
public class Metodos {

    Jugador inicio, ultimo;

    public boolean insertarOrdenado(String nombre, int numeroCamisa) {
        Jugador nuevo = new Jugador(nombre, numeroCamisa);
        if (inicio == null) {
            inicio = ultimo = nuevo;
            return true;
        }
        if ((inicio.numeroCamisa == nuevo.numeroCamisa) | (ultimo.numeroCamisa == nuevo.numeroCamisa)) {
            return false;
        }
        if (nuevo.numeroCamisa < inicio.numeroCamisa) {
            nuevo.sig = inicio;
            inicio.ant = nuevo;
            inicio = nuevo;
            return true;
        }
        if (nuevo.numeroCamisa > ultimo.numeroCamisa) {
            ultimo.sig = nuevo;
            nuevo.ant = ultimo;
            ultimo = nuevo;
            return true;
        }
        Jugador aux = inicio;
        while (aux != null) {
            if (nuevo.numeroCamisa == aux.numeroCamisa) {
                return false;
            }
            if (nuevo.numeroCamisa < aux.numeroCamisa) {
                aux.ant.sig = nuevo;
                nuevo.ant = aux.ant;
                nuevo.sig = aux;
                aux.ant = nuevo;
                return true;
            }
            aux = aux.sig;
        }
        return false;
    }

    public void mostrar() {
        Jugador aux = inicio;
        while (aux != null) {
            System.out.println(aux.nombre + " " + aux.numeroCamisa);
            aux = aux.sig;
        }
    }
}
