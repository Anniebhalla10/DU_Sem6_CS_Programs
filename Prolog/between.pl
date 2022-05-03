

between(N1,N2,[N2|R]):-
  Temp = N2-1,
  between( N1, Temp, R).

 
  
