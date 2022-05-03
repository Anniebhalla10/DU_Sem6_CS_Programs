conc([],L2,L2).

conc( [X|L1], L2, [X|L3]):-
		conc(L1,L2,L3).


flatten([],[]):- !.

flatten([H|T], Ans):-
  !,
flatten(H, H1),
flatten(T, T1),
conc(H1, T1, Ans).

flatten(L, [L]).