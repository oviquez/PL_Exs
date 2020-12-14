%% Grafo
vertice([i,[a,b]]).   %%        a ---- c ---- x
vertice([a,[i,c,d]]). %%      /   \  /
vertice([b,[i,c,d]]). %%     /     \/
vertice([c,[a,b,x]]). %%   i       X
vertice([d,[a,b,f]]). %%     \    / \
vertice([f,[d]]).     %%      \  /   \
vertice([x,[c]]).     %%        b ---- d ---- f

%% función miembro
miembro(E,[E|_]).
miembro(E,[_|Cola]):- miembro(E,Cola).

%% función vecinos
vecinos(Nodo,Res):- vertice([Nodo|[Vecinos|_]]), Res = Vecinos.  %% obtener los vecinos es simple, son la cabeza de la cola de la lista (cual lista???, los hchos en la BD)

%% función map
map([Car_ruta|Cdr_ruta],Res):- vecinos(Car_ruta,Res_vecinos),   %% obtiene los vecinos del car de la ruta
                               map_aux([Car_ruta|Cdr_ruta],Res_vecinos,Res). %% se separan aquellos vecinos que no son miembros de la ruta

map_aux(_,[],[]).
map_aux(Ruta,[Car_vecinos|Cdr_vecinos],Res):- miembro(Car_vecinos,Ruta), ! , map_aux(Ruta,Cdr_vecinos,Res). %% si el vecino es miembro de la ruta, no se incluye
map_aux(Ruta,[Car_vecinos|Cdr_vecinos],[Car_vecinos|Res]):- map_aux(Ruta,Cdr_vecinos,Res). %% si el vecino no es miembro de la ruta, si se incluye

%% función extender
extender(Ruta,Res_extender):- map(Ruta,Res_map), extender_aux(Ruta,Res_map,Res_extender). %% obtiene los vecinos por los que se puede extender y se extiende por ellos

extender_aux(_,[],[]). %% cuando se agotan todas las posibles extensiones, entonces []
extender_aux(Ruta,[Cabeza_map|Cola_map],[[Cabeza_map|Ruta]|Res]):- extender_aux(Ruta,Cola_map,Res). %% cada una de las posibles visitas se anexa a la cabeza de la ruta (por separado)
                                      %% |_______________|
%% función profundidad
prof(Inicio,Final,Res):- prof_aux([[Inicio]],Final,Res2),reverse(Res2,Res).   %%realiza la búsqueda en profundidad y le da vuelta al resultado

prof_aux([],_,[]). %% si ninguna de las rutas es el estado final, el resultado es []
prof_aux([Car_rutas|_],Fin,Res):- funcion_car(Car_rutas,Aux), Aux == Fin, Res=Car_rutas. %% resultado válido cuando la cabeza de la cabeza de la lista es ifgual al objetivo deseado
prof_aux([Car_rutas|Cdr_rutas],Fin,Res):- extender(Car_rutas,Res_extender), %% extiende la primera ruta de la lista
                                          append(Res_extender,Cdr_rutas,Res_append), %% pega las extensiones con el resto de las rutas que se tenían (para no perder posibles caminos extra - NO SE PODA EL ÁRBOL)
                                          prof_aux(Res_append,Fin,Res). %% llama recursivo con las rutas ampliadas



funcion_car([Head|_],Head). %% funcion para obtener el la cabeza de una lista
