%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File learner.pl                                                              %
% Un peque�o programa que modifica su propia base de conocimientos.            %
% Autor: Oscar V�quez. Lenguajes de Programaci�n                               %
% Fecha: 09/10/2007                                                            %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%Reglas para cosultas

start :- dynamic(capital_of/2),
         consult('bdc.pl'),
         nl,
         write('Escribe los nombres completamente en min�sculas,'), nl,
         write('seguidos de un punto.'), nl,
         nl,
         process_a_query.

process_a_query :- write('Pa�s? '),
                   read(Pais),
                   answer(Pais).

% Si el usuario ingresa "stop.", entonces grabar la nueva
% base de conocimientos y salir.
answer(stop) :- write('Grabando la base de conocimientos...'), nl,
                tell('bdc.pl'),
                listing(capital_of),
                told,
                write('Listo.'), nl.

% Si el pa�s ya est� en la base de conocimientos, entonces retornar
% el nombre de su capital.
answer(Pais) :- capital_of(Pais, Ciudad),
                write('La capital de '),
                write(Pais),
                write(' es '),
                write(Ciudad), nl,
                nl,
                process_a_query.

% Si el pa�s no est� en la base de conocimientos, entonces pedir
% el nombre de la capital e ingresar este fact a la base.
answer(Pais) :- \+ capital_of(Pais, Ciudad), %% analogo a "not(capital_of(Pais, Ciudad))"
                write('No conozco la capital de ese pa�s.'), nl,
                write('Por favor, dime cual es.'), nl,
                write('Capital? '),
                read(Ciudad),
                write('Gracias.'), nl, nl,
                assert(capital_of(Pais, Ciudad)),
                process_a_query.

