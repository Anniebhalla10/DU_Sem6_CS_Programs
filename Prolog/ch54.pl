member(X,[X|T]).

member(X,[H|T]):-
		member(X,T).


findCandi([], _, []).

% recursive line

findCandi([H|T], RO, [H|T1]) :-
    not(member(H, RO)),
    findCandi(T, RO, T1), !.

findCandi([_|T], RO, L) :-
    findCandi(T, RO, L).

 