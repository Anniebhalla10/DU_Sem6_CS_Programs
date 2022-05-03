% if x and y are different then true else false

different(X,X):- !,fail.

different(X,Y).

different1(X,Y):-
X=Y, !,fail
;
true.