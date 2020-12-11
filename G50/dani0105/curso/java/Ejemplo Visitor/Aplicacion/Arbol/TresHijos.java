package Aplicacion.Arbol;

public class TresHijos extends Arbol {

  public TresHijos(int num_arbol) {
    super (num_arbol);
    hijo1 = null;
    hijo2 = null;
    hijo3 = null;
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

  public Arbol getHijo3() {
    return hijo3;
  }

  public void setHijo3(Arbol hijo3) {
    this.hijo3 = hijo3;
  }

  public Object visit(Visitor v, Object o) {
    return v.visitTresHijos(this, o);
  }  
  
  private Arbol hijo1;
  private Arbol hijo2;
  private Arbol hijo3;
}
