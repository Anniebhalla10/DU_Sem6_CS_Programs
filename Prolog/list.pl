member(X,[X|T]).

member(X,[H|T]):-
		member(X,T).

%Concatenation of L1 and L2 to L3

conc([],L2,L2).

conc( [X|L1], L2, [X|L3]):-
		conc(L1,L2,L3).

member1(X,L):-
conc(_, [X|_], L).



deleteLast3(L,L1):-
conc(L1,[_,_,_], L).

deletefirstlast3(L,L2):-
conc([_,_,_], LT, L), deleteLast3(LT,L2).

last(X,L):-
conc(L2,[X],L).

last1(X,[X]).
last1(X,[_|Z]):- last1(X,Z).

add(X,L,[X|L]).

member3(X, [X|T]):- !.

member3(X, [H|T]):-  member3(X,T).

add1(X,L,L) :- member3(X,L), !.    %not add if item is already in list
add1(X,L,[X|L]).		   %this succeeds if we give L

del(X, [X|Tail], Tail).
del(X, [Y|Tail], [Y|Tail1]):- del(X, Tail, Tail1).

insert(X, List, NewList):-
del(X, NewList, List).

member2(X,L):-
del(X,L,_).


sublist(S,L):-
	conc(L1,L2,L),  
	conc( S, L3, L2).

permutation([],[]).
permutation([X|L], P):-
	permutation(L,L1),
	insert(X,L1, P).

permutation1([],[]).
permutation1(L, [X|P]):-
		del(X, L, L1),
		permutation1(L1,P).


evenlist([_,_]).
evenlist(L):-
	conc( L1, [X,Y], L),
	evenlist(L1).

oddlist([_]).
oddlist(L):-
	conc( L1, [X,Y], L),
	oddlist(L1).

reverselist([H|T],ReversedList):-
	reverseListHelper( T, [H], ReversedList).

reverseListHelper([], Acc, Acc).

reverseListHelper( [H|T] , Acc, ReversedList):-
	reverseListHelper(T, [H|Acc], ReversedList).

palindrome(List):- reverselist( List, List).


shift([],[]).

shift([H|T1], L2):-
	conc( T1, [H], L2).