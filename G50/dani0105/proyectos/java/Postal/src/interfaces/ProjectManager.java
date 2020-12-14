package interfaces;

import java.io.File;

public interface ProjectManager {
    public boolean saveProject(String name, String top, String bottom, int font,int size, File original);
    public void cancel();
}
