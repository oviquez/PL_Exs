
package toy;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;

/**
 *
 * @author Daniel
 */
public class Ball extends Toy{

   
    public Ball(int number,int lote){
        this.number =number;
        this.lote = lote;
        this.name = "Balon";
    }
    
    @Override
    public boolean assembly(DefaultListModel line) {
        Random rand = new Random(); 
        int total = 0;
        try {
            int time = rand.nextInt(this.maxAssemblyTime-this.minAssemblyTime) + this.minAssemblyTime;
            total += time;
            Thread.sleep(time *1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(Car.class.getName()).log(Level.SEVERE, null, ex);
        }
        line.addElement("Balon Inflado en "+total+" Segundos");
        this.isAssembly = true;
        return true;
    }
}
