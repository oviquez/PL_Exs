invertir([],L):-write(L).
invertir([H|T],[H1|T1]):-
    invertir(T,[H|[H1|T1]]),!.
invertir([H|T]):-
    invertir(T,[H]),!.

