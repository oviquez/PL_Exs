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
public class Jugador {

    String nombre;
    int numeroCamisa;
    Jugador  sig, ant;
    
    public Jugador(String nombre, int numeroCamisa) {
        this.nombre = nombre;
        this.numeroCamisa = numeroCamisa;
        this.sig = this.ant = null;
    }

}
