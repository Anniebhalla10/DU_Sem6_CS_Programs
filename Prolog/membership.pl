member(X,[X|T]).

member(X,[H|T]):-
		member(X,T).

%i do not want to backtrack so ill use cut !

member1(X, [X|T]):- !.

member1(X, [H|T]):-  member1(X,T).