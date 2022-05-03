bars([]). 

bars([N|L]) :-
	stars(N), nl, 
	bars(L). 

stars( N) :-
	N >0, 
	write(*), 
	N1 is N-1, 
	stars( N1). 

stars(N) :-
N =<0. 