means(0, null).
means(1, eins).
means(2, zwei).
means(3, drei).
means(4, vier).
means(5, funf).

translate([],[]).

translate([X|L1], [W|L2]):-
   translate(L1,L2),
   means(X,W).
   