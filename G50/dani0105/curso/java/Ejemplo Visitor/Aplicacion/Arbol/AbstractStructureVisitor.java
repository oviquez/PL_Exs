package Aplicacion.Arbol;

/**
 * Created by oviquez on 30/10/2018.
 */
public abstract class AbstractStructureVisitor<T> implements Visitor<T> {
    public AbstractStructureVisitor() {
    }
    public T visit(Arbol<T> tree) {
        return tree.visit(this,null);
    }
}
