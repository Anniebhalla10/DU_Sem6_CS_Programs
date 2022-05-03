parent(pam, bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).
female(pam).
female(liz).
female(pat).
female(ann).
male(jim).
male(bob).
male(tom).

mother(X,Y):-			% x mother of y
 parent(X,Y),
 female(X).

sister(X,Y):-
 parent(Z,X),
 parent(Z,Y),
 female(X),
 X\=Y.

grandparent(X,Z):-
 parent(X,Y),
 parent(Y,Z).

ancestor(X,Z):-
 parent(X,Z).

ancestor(X,Z):-
 parent(X,Y),
 ancestor(Y,Z).

+(X,Y).