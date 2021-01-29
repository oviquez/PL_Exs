
package main;

import java.util.ArrayList;
import line.PackageLine;
import toy.Toy;

/**
 *
 * @author Daniel
 */
public class PackageThread extends Thread{
    
    private ArrayList<Toy> queue;
    
    private ArrayList<PackageLine> Lines;
    
    public PackageThread(){
        this.queue = new ArrayList<>();
        this.Lines = new ArrayList<>();
    }
    
    public void addInQueue( Toy toy){
        this.queue.add(toy);
    }
    
    public void addline(PackageLine line){
        this.Lines.add(line);
    }
    
    
    @Override
    public void run(){
        this.Lines.forEach((element)->{
           element.start();
        });       
        while(true){
            System.out.println(this.queue.size());
            if(!this.queue.isEmpty()){
                this.Lines.forEach((element)->{
                    if(element.getWorking()){
                        element.a = this.queue.remove(0);
                    }
                 });  
            }
        }
    }

}
