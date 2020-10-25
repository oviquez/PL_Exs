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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Metodos met = new Metodos();
        met.insertarOrdenado("Messi", 10);
        met.insertarOrdenado("CR7 el bicho", 7);
        met.insertarOrdenado("Keylor Navas", 30);
        met.mostrar();
    }

}
