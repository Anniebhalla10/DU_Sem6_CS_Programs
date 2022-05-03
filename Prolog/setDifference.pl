member(X,[X|T]):- !.

member(X,[H|T]):-
		member(X,T).


setHelper([], _, []).

% recursive line

setHelper([H|T], RO, [H|T1]) :-
    not(member(H, RO)),
    setHelper(T, RO, T1), !.

setHelper([_|T], RO, L) :-
    setHelper(T, RO, L).


set_difference(S1, S2, SetDiff):-
 setHelper(S1,S2,SetDiff).