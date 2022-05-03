findterm(Term):-
 see(data), 
 read_from_file(X),
 equal(X,Term),
 write( X), !.

equal(X, T):-
 X:=:T,
true;
false.