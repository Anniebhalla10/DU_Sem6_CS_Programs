
max(X,Y):-
(
X=Y-> write('both are equal');
X>Y -> (
Z is X,
write(Z)
);
(
Z is Y,
write(Z)
)

).




max(X,Y,X):- X>=Y.
max(X,Y,Y):- X<Y.

%using cut 

max(X,Y,X) :- X>=Y, !.

max(X,Y,Y).

%this will give problem therefor

max(X,Y, Max):-
  X>=Y, !, Max=X
;
Max= Y.