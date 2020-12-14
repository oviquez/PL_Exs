
% parte 1

calorias(paella,200).
calorias(gazpacho,150).
calorias(consome,300).
calorias(filete_de_cerdo,400).
calorias(pollo_asado,280).
calorias(bacalao,300).
calorias(trucha,160).
calorias(flan,200).
calorias(nueces_con_miel,500).
calorias(naranja,50).
comida(entrada,[paella,gazpacho,consome]).
comida(postre,[flan,nueces_con_miel,naranja]).
comida(carne,[filete_de_cerdo,pollo_asado]).
comida(pescado,[bacalao,trucha]).

%Ejercicio A



%Fin ejercicio A



%Ejercicio B
menor_en_calorias([],Menor,Aux):-Aux = Menor.

menor_en_calorias([Cabeza|Cola],Menor,Aux):-
   calorias(Cabeza,KCabeza),
   calorias(Menor,KMenor),
   KCabeza =< KMenor,
   menor_en_calorias(Cola,Cabeza,Aux).

menor_en_calorias([Cabeza|Cola],Menor,Aux):-
   calorias(Cabeza,KCabeza),
   calorias(Menor,KMenor),
   KCabeza>KMenor,
   menor_en_calorias(Cola,Menor,Aux).

%Estos son los que se ejecutan
%Usar: minimo(pollo_asado,K,L).
%Resultado: K = 480,L = [gazpacho,naranja,pollo_asado]
minimo(Elemento,K,Result):-
   comida(entrada,Entradas),
   member(Elemento,Entradas),
   calorias(Elemento,KElemento),

   comida(postre,[MenorPostre|Postres]),
   menor_en_calorias(Postres,MenorPostre,Result1),

   comida(carne,[MenorPrincipal|Carnes]),
   comida(pescado,Pescados),
   append(Carnes,Pescados,Lista),
   menor_en_calorias(Lista,MenorPrincipal,Result2),

   Result = [Result1,Result2,Elemento],
   calorias(Result1,A),
   calorias(Result2,B),
   K is A+B+KElemento.

%Estos son los que se ejecutan
%Usar: minimo(Flan,K,L).
%Resultado: K=510,L= [gazpacho, trucha, flan]
minimo(Elemento,K,Result):-
   comida(postre,Entradas),
   member(Elemento,Entradas),
   calorias(Elemento,KElemento),

   comida(entrada,[MenorPostre|Postres]),
   menor_en_calorias(Postres,MenorPostre,Result1),

   comida(carne,[MenorPrincipal|Carnes]),
   comida(pescado,Pescados),
   append(Carnes,Pescados,Lista),
   menor_en_calorias(Lista,MenorPrincipal,Result2),
   Result = [Result1,Result2,Elemento],
   calorias(Result1,A),
   calorias(Result2,B),
   K is A+B+KElemento.

%Estos son los que se ejecutan
%Usar: minimo(trucha,K,L).
%Resultado: K=360,L= [gazpacho, naranja, trucha]
minimo(Elemento,K,Result):-
   comida(carne,Carnes),
   comida(pescado,Pescados),
   append(Carnes,Pescados,Lista),

   member(Elemento,Lista),
   calorias(Elemento,KElemento),
   write("A"),

   comida(entrada,[MenorEntrada|Entradas]),
   menor_en_calorias(Entradas,MenorEntrada,Result1),

   comida(postre,[MenorPostre|Postres]),
   menor_en_calorias(Postres,MenorPostre,Result2),

   Result = [Result1,Result2,Elemento],
   calorias(Result1,A),
   calorias(Result2,B),
   K is A+B+KElemento.
%Fin ejercicio B


%parte 2

aciertos([],[],A,Num):-A=Num.

aciertos([CLista1|TLista1],[CLista2|TLista2],A,Num):-
   CLista1 = CLista2,
   Total is Num+1,
   aciertos(TLista1,TLista2,A,Total).

aciertos([CLista1|TLista1],[CLista2|TLista2],A,Num):-
   not(CLista1 = CLista2),
   aciertos(TLista1,TLista2,A,Num).


coincidencias(_,[],C,Num):-C=Num.

coincidencias(Lista1,[Cabeza|Lista2],C,Num):-
    member(Cabeza,Lista1),
    Total is Num + 1,
    coincidencias(Lista1,Lista2,C,Total).

coincidencias(Lista1,[Cabeza|Lista2],C,Num):-
    not(member(Cabeza,Lista1)),
    coincidencias(Lista1,Lista2,C,Num).

%Este es el que se ejecuta
%
%Usar: mastermind([1,2,3,4,5,6],[1,23,3,4,5,6],A,C).
%Resultado: A=5, C=0.
mastermind(Lista1,Lista2,A,C):-
    coincidencias(Lista1,Lista2,T,0),
    aciertos(Lista1,Lista2,A,0),
    C is T-A.

