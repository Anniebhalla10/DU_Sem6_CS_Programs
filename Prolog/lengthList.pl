length( [], 0).

length( [_|T], N):-
	length( T, N1),
	N is 1+N1.