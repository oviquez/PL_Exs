
package toy;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JList;

/**
 *
 * @author Daniel
 */
public class Car extends Toy{

    public Car(int number,int lote){
        this.number =number;
        this.lote = lote;
        this.name = "Carro";
    }
    @Override
    public boolean assembly(DefaultListModel line) {
        Random rand = new Random(); 
        int total = 0;
        for(short i = 0; i <4; i++){
            try {
                int time = rand.nextInt(this.maxAssemblyTime-this.minAssemblyTime) + this.minAssemblyTime;
                total += time;
                Thread.sleep(time *1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Car.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        line.addElement("Ruedas Colocadas en "+total+" Segundos");
        total = 0;
        for(short i = 0; i <2; i++){
            try {
                int time = rand.nextInt(this.maxAssemblyTime-this.minAssemblyTime) + this.minAssemblyTime;
                total += time;
                Thread.sleep(time *1000);
                
            } catch (InterruptedException ex) {
                Logger.getLogger(Car.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        line.addElement("Puertas Colocadas en "+total+" Segundos");
        this.isAssembly = true;
        return true;
    }
}
