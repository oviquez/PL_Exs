package Aplicacion.Dibujar_Arbol;

import Aplicacion.Arbol.*;

//Implementa los métodos para imprimir el AST utilizando Visitors
public class PrettyPrintAST implements Visitor
{
   
  public void imprimir(Arbol raiz)
  {
    raiz.visit(this,new Integer(0));
  }
  
  public void printtab(int n)
  {
    for(int num=n; num != 0; num--)
      System.out.print("|+++");
    System.out.print(">");
  }
  // TODOS LOS M�TODOS PARA IMPRIMIR EL AST
  @Override
  public Object visitUnHijo(UnHijo arbol, Object o)
  {
    int numaux = ((Integer)o).intValue();
    printtab(numaux);
    System.out.println(arbol.get_num_arbol());
    
    arbol.getHijo1().visit(this,new Integer(numaux+1));
    return null;
  }

  @Override
  public Object visitDosHijos(DosHijos arbol, Object o)
  {
    int numaux = ((Integer)o).intValue();
    printtab(numaux);
    System.out.println(arbol.get_num_arbol());
    arbol.getHijo1().visit(this, new Integer(numaux+1));
    arbol.getHijo2().visit(this, new Integer(numaux+1));
    return null;
  }

  @Override
  public Object visitTresHijos(TresHijos arbol, Object o)
  {
    int numaux = ((Integer)o).intValue();
    printtab(numaux);
    System.out.println(arbol.get_num_arbol());
    arbol.getHijo1().visit(this, new Integer(numaux+1));
    arbol.getHijo2().visit(this, new Integer(numaux+1));
    arbol.getHijo3().visit(this, new Integer(numaux+1));
    return null;
  }
  @Override
  public Object visitHoja(Hoja arbol, Object o)
  {
    int numaux = ((Integer)o).intValue();
    printtab(numaux);
    System.out.println("("+arbol.get_num_arbol()+")");
    //printtab(numaux);
    //System.out.println(arbol.getElemento());
    return null;
  }
}