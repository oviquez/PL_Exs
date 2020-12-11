package Aplicacion.Dibujar_Arbol;

import Aplicacion.Arbol.*;

public class Dibujar extends BaseVisitor
{

  @Override public Object visitUnHijo(UnHijo arbol, Object o)
  {
    System.out.println(arbol.get_num_arbol());
    visit(arbol.getHijo1());
    return null;
  }
  @Override public Object visitDosHijos(DosHijos arbol, Object o)
  {
    System.out.println(arbol.get_num_arbol());
    visit(arbol.getHijo1());
    visit(arbol.getHijo2());
    return null;
  }
  @Override public Object visitTresHijos(TresHijos arbol, Object o)
  {
    System.out.println(arbol.get_num_arbol());
    visit(arbol.getHijo1());
    visit(arbol.getHijo2());
    visit(arbol.getHijo3());
    return null;
  }

  @Override public Object visitHoja(Hoja arbol, Object o)
  {
    System.out.println(arbol.get_num_arbol());
    //System.out.println(arbol.getElemento());
    return null;
  }
}