package Aplicacion.Arbol;

/**
 * Clase Abstracta Arbol que define el comportamiento 
 * general de una estructura de datos heterogenea. 
 * <hr>
 * </hr>
 *
 * @author  Oscar Víquez Acuña
 */

public abstract class Arbol<T> {

  public Arbol (int n_a) {
    num_arbol = n_a;
  }

  public int get_num_arbol() {
    return num_arbol;
  }

  /**
   * Método Abstracto "visit" que debe ser implementado
   * dentro de las subclases de esta superclase Abstracta.
   * 
   * @param    v Objeto del cual se invocara la acción de visita
   * @param    o Objeto genérico que se puede utilizar dependiendo del contexto de la visita.
   * @return   Un objeto generico que se puede utilizar dependiendo del contexto de la visita.
   */
  public abstract T visit(Visitor v, T o);
  
  private int num_arbol;
}
