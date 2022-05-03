eval(X,Y,Z):-
 X>Y,
 Z is X;
 Z is Y.

eval( X, 5, Z):-
  X>5,
Z is 1;
Z is 0.