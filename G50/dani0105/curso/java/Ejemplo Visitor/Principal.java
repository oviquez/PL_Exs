import Aplicacion.Arbol.*;
import Aplicacion.Dibujar_Arbol.*;

public class Principal
{
  public static void main(String[] args)
  {
    Arbol raiz;
    raiz = new TresHijos(5);
    
    ((TresHijos) raiz).setHijo1(new DosHijos(6));
    ((TresHijos) raiz).setHijo2(new Hoja(30,8));
    ((TresHijos) raiz).setHijo3(new UnHijo(4));
    
    ((DosHijos)((TresHijos) raiz).getHijo1()).setHijo1(new Hoja(10,2));
    ((DosHijos)((TresHijos) raiz).getHijo1()).setHijo2(new Hoja(20,10));
    
    ((UnHijo)((TresHijos) raiz).getHijo3()).setHijo1(new Hoja(40,7));
    
    
    
    

    // imprimir con clase "imprimir"
    Dibujar i = new Dibujar();
    raiz.visit(i,null);
    
    // imprimir con clase "PrettyPrint"
    PrettyPrintAST p = new PrettyPrintAST();
    p.imprimir(raiz);
    
  }
}
