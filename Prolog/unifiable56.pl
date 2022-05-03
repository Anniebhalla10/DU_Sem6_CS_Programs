unifiable([],_,[]).

unifiable([H|L1], X, L2):-
 not(H = X),
 unifiable(L1, X,L2), !.

unifiable([H|L1], X,[H|L2]):-
 unifiable(L1,X,L2).