% mary likes all animals but snakes

likes(mary, X):- animals(X).

likes1(mary,X):-
snake(X),!,fail.

likes1(mary,X):-
animal(X).


% we can write this compactly as

likes(mary,X):-
 snake(X),!,fail
;
animal(X).


