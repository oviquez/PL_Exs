
package objects;

import com.drew.imaging.ImageMetadataReader;
import com.drew.imaging.ImageProcessingException;
import com.drew.metadata.Directory;
import com.drew.metadata.Metadata;
import com.drew.metadata.Tag;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.imageio.ImageReader;
import javax.imageio.metadata.IIOMetadata;
import javax.imageio.stream.ImageInputStream;
import javax.swing.ImageIcon;
import javax.imageio.*;
import javax.imageio.stream.*;
import javax.imageio.metadata.*;
import org.w3c.dom.*;

/**
 *
 * @author Daniel
 */
public class Project {
    
    private final String PATH = "images/";
    private final String EXTENSION = ".png";
    private String name;
    
    public Project(String name){
        this.name = name;
    }
    
    public Project(String name, String top, String bottom, int font,int size, File original) throws IOException {
        this.name = name;
        this.copyFile(original.getPath(), this.PATH+this.name+ this.EXTENSION); //Copio el original y lo guardo en el proyecto
        this.copyFile( this.PATH+this.name+ this.EXTENSION, this.PATH+this.name+"-postal"+this.EXTENSION); // copio el del proyecto para poder generar una postal
        this.generatePostal(top,bottom,size,font);
        
    }
    
    private void generatePostal(String top,String bottom,int size,int font) throws IOException{
        Runtime rt = Runtime.getRuntime();
        String sizeFont = "-s";
        switch(size){
            case 2:
                sizeFont = "-m";
            case 3:
                sizeFont = "-h";
        }
        String command = "postal \""+this.PATH+this.name+"-postal"+this.EXTENSION+"\" -t \""+top+"\" -b \""+bottom+"\" "+sizeFont+" -f "+font;
        rt.exec(new String[]{"cmd.exe","/c",command});
    }
    
    private boolean copyFile(String pathFrom ,String pathTo) throws FileNotFoundException, IOException{
        File postal = new File(pathTo);
        InputStream in = new FileInputStream(pathFrom);
        OutputStream out = new FileOutputStream(postal);
        byte[] buf = new byte[1024];
        int len;

        while ((len = in.read(buf)) > 0) {
          out.write(buf, 0, len);
        }
        in.close();
        out.close(); 
        return true;
    }

    public String getName() {
        return name;
    }
    
    public ImageIcon getImage(){
        return new ImageIcon(this.PATH+this.name+this.EXTENSION);
    }
    
    public ImageIcon getPostal(){
        return new ImageIcon(this.PATH+this.name+"-postal"+this.EXTENSION);
    }
    
    @Override
    public String toString(){
        return this.name;
    }
    
    public ArrayList<String> getMetaData(boolean postal){
        try {
            File file;
            if(postal)
                file = new File( this.PATH+this.getName()+"-postal"+this.EXTENSION );
            else
                file = new File( this.PATH+this.getName()+this.EXTENSION);
            Metadata metadata = ImageMetadataReader.readMetadata(file);
            ArrayList<String> propieties = new ArrayList<>();
            for (Directory directory : metadata.getDirectories()) {
                for (Tag tag : directory.getTags()) {
                    propieties.add(tag.getTagName()+": "+tag.getDescription());
                }
            }
            return propieties;
        } catch (ImageProcessingException ex) {
            Logger.getLogger(Project.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        } catch (IOException ex) {
            Logger.getLogger(Project.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
}
