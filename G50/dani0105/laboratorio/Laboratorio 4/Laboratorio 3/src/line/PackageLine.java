
package line;

import java.util.ArrayList;
import javax.swing.DefaultListModel;
import toy.Toy;

/**
 *
 * @author Daniel
 */
public class PackageLine extends Line {
   
    public Toy a ;
    
    public PackageLine( DefaultListModel line){
        this.queue = new ArrayList<>();
        this.working = false;
        this.line = line;
    }
     
    @Override
    public void run(){
        while(true){
            if(this.a != null){
                System.out.println("Working");
                work(a);
                this.a = null;
            }
        }
    }
    
    @Override
    public Toy work(Toy toy) {
        this.working = true;
        this.line.addElement("Enpaquetando "+toy.getName());
        this.working = !toy.pack(line);
        return toy;
    }

}
