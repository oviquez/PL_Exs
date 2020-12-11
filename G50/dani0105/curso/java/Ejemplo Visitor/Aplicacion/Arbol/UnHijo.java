package Aplicacion.Arbol;


public class UnHijo extends Arbol {

  public UnHijo(int num_arbol) {
    super (num_arbol);
    hijo1 = null;
  }

  public Arbol getHijo1() {
    return hijo1;
  }

  public void setHijo1(Arbol hijo1) {
    this.hijo1 = hijo1;
  }

  public Object visit(Visitor v, Object o) {
    return v.visitUnHijo(this, o);
  }
  
  private Arbol hijo1;
}
