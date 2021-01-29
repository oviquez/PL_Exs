
package line;

import java.util.ArrayList;
import javax.swing.DefaultListModel;
import main.PackageThread;
import toy.Toy;

/**
 *
 * @author Daniel
 */
public class AssemblyLine extends Line {
    
    private PackageLine next;
   
    public AssemblyLine( DefaultListModel line,PackageLine next){
        this.queue = new ArrayList<>();
        this.working = false;
        this.line = line;
        this.next = next;
    }
        
    @Override
    public void run(){
        while(this.queue.size() >0){
            Toy element = this.queue.remove(0);
            this.work(element);
            this.next.work(element);
            
        }
        
    }
    
    @Override
    public Toy work(Toy toy) {
        this.working = true;
        this.line.addElement("Ensamblando "+toy.getName());
        this.working = !toy.assembly(line);
        return toy;
    }

}
