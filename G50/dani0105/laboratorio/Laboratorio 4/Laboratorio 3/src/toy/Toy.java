
package toy;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;

/**
 *
 * @author Daniel
 */
public abstract class Toy {
    
    protected int number;
    protected int lote;
    protected String name;
    
    protected boolean isAssembly;
    protected boolean isPackage;
    
    protected final int minAssemblyTime = 1;
    protected final int maxAssemblyTime = 3;
    
    protected final int minPackageTime = 1;
    protected final int maxPackageTime = 2;
    
    public String getName(){
        return this.name;
    }

    public abstract boolean assembly(DefaultListModel line);
    
    public boolean pack(DefaultListModel line){
        Random rand = new Random(); 
        try {
                int time = rand.nextInt(this.maxAssemblyTime-this.minAssemblyTime) + this.minAssemblyTime;
                Thread.sleep(time *1000);
                line.addElement(this.name+" empacado en "+time+" Segundos");
                
            } catch (InterruptedException ex) {
                Logger.getLogger(Car.class.getName()).log(Level.SEVERE, null, ex);
            }
        this.isPackage = true;
        return true;
    }
}
