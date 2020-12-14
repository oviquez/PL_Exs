
package objects;

import com.drew.imaging.ImageMetadataReader;
import com.drew.imaging.ImageProcessingException;
import com.drew.metadata.Directory;
import com.drew.metadata.Metadata;
import com.drew.metadata.Tag;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import view.Main;


public class Project {
    
    private final String PATH = "images/";
    private final String EXTENSION = ".png";
    private String name;
    private String extension;
    
    public Project(String name,String extension){
        this.name = name;
        this.extension = "."+extension;
    }
    
    public Project(String name, String top, String bottom, int font,int size, File original) throws IOException {
        this.name = name;
        String[] parts = original.getName().split("\\.");
        this.extension = "."+parts[parts.length-1];
        this.copyFile(original.getPath(), this.PATH+this.name+ this.extension); //Copio el original y lo guardo en el proyecto
        this.copyFile( this.PATH+this.name+ this.extension, this.PATH+this.name+"-postal"+this.EXTENSION); // copio el del proyecto para poder generar una postal
        this.generatePostal(name,top,bottom,size,font);
    }
    
    public String getImagePath(){
        return this.PATH+name+this.extension;
    }
    
    private void generatePostal(String name,String top,String bottom,int size,int font) throws IOException{
        String sizeFont = "-s";
        switch(size){
            case 2:
                sizeFont = "-m";
                break;
            case 3:
                sizeFont = "-h";
                break;
        }
        
        String fonType = "-a";
        switch(font){
            case 2:
                fonType = "-i";
                break;
            case 3:
                fonType = "-r";
                break; 
        }
        System.out.println(fonType);
        File postal = new File("images/c/postal.exe");
        File image = new File(this.PATH+name+"-postal"+this.EXTENSION);
        try {
            ProcessBuilder exec = new ProcessBuilder(postal.getAbsolutePath(),image.getAbsolutePath(),"-t "+top,fonType,"-b "+bottom,sizeFont);
            Process p = exec.start();

            InputStream is = p.getInputStream();
            /* Se prepara un bufferedReader para poder leer la salida más comodamente. */
            BufferedReader br = new BufferedReader (new InputStreamReader (is));
            
            // Se lee la primera linea
            String aux = br.readLine();
            
            // Mientras se haya leido alguna linea
            while (aux!=null)
            {
                // Se escribe la linea en pantalla
                System.out.println (aux);
                
                // y se lee la siguiente.
                aux = br.readLine();
            }
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }  
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
        return new ImageIcon(this.PATH+this.name+this.extension);
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
                file = new File( this.PATH+this.getName()+this.extension);
            
            ArrayList<String> propieties = new ArrayList<>();
            if(postal){
                Metadata metadata = ImageMetadataReader.readMetadata(file);
                
                for (Directory directory : metadata.getDirectories()) {
                    for (Tag tag : directory.getTags()) {
                        propieties.add(tag.getTagName()+": "+tag.getDescription());
                    }
                }
                return propieties;
            }
            ImageIcon icon = this.getImage();
          
            propieties.add("Width: "+icon.getIconWidth());
            propieties.add("Height: "+icon.getIconHeight());
            
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
