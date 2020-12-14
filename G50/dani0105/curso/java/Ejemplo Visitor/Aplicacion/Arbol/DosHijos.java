package Aplicacion.Arbol;

public class DosHijos extends Arbol {

  public DosHijos(int num_arbol) {
    super (num_arbol);
    this.hijo1 = null;
    this.hijo2 = null;
  }

  public Arbol getHijo1() {
    return hijo1;
  }

  public void setHijo1(Arbol hijo1) {
    this.hijo1 = hijo1;
  }

  public Arbol getHijo2() {
    return hijo2;
  }

  public void setHijo2(Arbol hijo2) {
    this.hijo2 = hijo2;
  }

  public Object visit(Visitor v, Object o) {
    return v.visitDosHijos(this, o);
  }

  private Arbol hijo1;
  private Arbol hijo2;
 
}
