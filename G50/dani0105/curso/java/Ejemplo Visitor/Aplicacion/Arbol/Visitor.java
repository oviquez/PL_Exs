package Aplicacion.Arbol;

public interface Visitor<T> {

  public abstract T visitUnHijo(UnHijo ctx, T o);
  public abstract T visitDosHijos(DosHijos ctx, T o);
  public abstract T visitTresHijos(TresHijos ctx, T o);
  public abstract T visitHoja(Hoja ctx, T o);

}
