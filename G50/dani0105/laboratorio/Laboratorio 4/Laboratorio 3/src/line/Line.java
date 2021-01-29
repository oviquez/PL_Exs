
package line;

import java.util.ArrayList;
import javax.swing.DefaultListModel;
import toy.Toy;

/**
 *
 * @author Daniel
 */
public abstract class Line extends Thread {

    protected ArrayList<Toy> queue;
    
    protected boolean working;
    protected DefaultListModel line;
    
    public abstract Toy work(Toy toy);
    
    public boolean getWorking(){
        return this.working;
    }
    
    public void addInQueue( Toy toy){
        this.queue.add(toy);
    }
}
