package Aplicacion.Arbol;

public class Hoja extends Arbol {

  public Hoja(int element, int num_arbol) {
    super (num_arbol);
    elemento = element;
  }
  
  public Object visit(Visitor v, Object o) {
    return v.visitHoja(this, o);
  }
  
  public int getElemento(){
    return elemento;
  }
  
  private int elemento;
}
