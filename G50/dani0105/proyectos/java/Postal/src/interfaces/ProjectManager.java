/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaces;

import java.io.File;
import objects.Project;

/**
 *
 * @author Daniel
 */
public interface ProjectManager {
    
    public boolean saveProject(String name, String top, String bottom, int font,int size, File original);
    public void cancel();
}
