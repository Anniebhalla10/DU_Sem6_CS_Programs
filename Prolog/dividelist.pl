evenlength([]).
evenlength([_,_|List]) :-
    evenlength(List), !.

oddlength([_]).
oddlength([_,_|List]) :-
    oddlength(List), !.


dividelist([],[],[]).

dividelist([H|L], [H|L1], L2) :-
    oddlength(L),
    dividelist(L, L1, L2).
dividelist([H|L], L1, [H|L2]) :-
    evenlength(L),
    dividelist(L, L1, L2).