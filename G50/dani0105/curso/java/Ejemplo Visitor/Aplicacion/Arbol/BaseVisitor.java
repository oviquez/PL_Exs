package Aplicacion.Arbol;

/**
 * Created by oviquez on 30/10/2018.
 */
public class BaseVisitor<T> extends AbstractStructureVisitor<T>{
    @Override public Object visitUnHijo(UnHijo ctx, Object o){
        return visit(ctx);
    }
    @Override public Object visitDosHijos(DosHijos ctx, Object o){
        return visit(ctx);
    }
    @Override public Object visitTresHijos(TresHijos ctx, Object o){
        return visit(ctx);
    }
    @Override public Object visitHoja(Hoja ctx, Object o){
        return visit(ctx);
    }
}
