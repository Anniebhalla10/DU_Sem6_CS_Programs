% Practicals Max of two numbers

max(X,Y,Max):- X>=Y, !,
Max is X
;
 Max is Y. 

% Factorial of a number

fact(0,1).

fact(N, F):-
	N1 is N-1,
	fact(N1, F1),
        F = F1*N.

% Fibonacci series

generate_fib(0,1).

generate_fib(1, 1).

generate_fib(N,T):-
 N1 is N-1,
 generate_fib(N1, T1),
  N2 is N-2,
 generate_fib(N2, T2),
 T is T1+T2.


% GCD of two numbers

gcd(X,X,X).

gcd(X,Y, D):-
 X<Y,
Y1 is Y-X,
gcd(X, Y1, D).

gcd(X,Y,D):-
 Y<X,
 gcd(Y,X,D).

%power 

pow( Num, 1, Num).
pow( Num , P, Ans):-
        P1 is P-1,
	pow( Num, P1, A1),
 	Ans is A1*Num.

%multiplication of 2 numbers

multi( N1, 1, N1):- !.

multi(N1,N2, R):-
   Temp is N2-1,
   multi(N1, Temp, R1),
   R is R1+N1.

% member

member( X, [X|T]):- !.

member(X, [_|T]):- member(X,T).

% concatenation

conc([], L2,L2).

conc([H|L1], L2, [H|L3]):-
	conc(L1,L2,L3).

% reverse of list

reverse([],[]).

reverse([H|T], R):-
  reverse(T,R1),
  conc(R1, [H], R).

reverselist( [H|T], RL):-
  rlhelper( T, [H], RL).

rlhelper([], Acc, Acc).

rlhelper( [H|T], Acc, RL):-
 rlhelper(T, [H|Acc], RL).


% Pallindrome

isEqual([],[]):- true.
isEqual([H1|_], [H2|_]):- false.

isEqual( [H1|T], [H1|T2]):- isEqual(T1,T2).

palindrome(L):- 
	reverse(L,R),
 	isEqual(L,R).

% sumlist

sumlist([],0).

sumlist([H|T], S):-
	sumlist(T,S1),
	S is S1+H.

% evenlength oddlength

evenlength([]).
evenlength([_|T):- oddlength(T).

oddlength([_].
oddlength([_|T]):- evenlength(T).

% nth element

element(1, [H|T], H).

element( N, [H|T], X):-
	N1 is N-1,
  	elemenet( N1, T, X).

% max number in list

maxlist( [H], H).
maxlist( [H|T], M):-
	maxlist(T, M1),
	H< M1,
	M is M1;
 	M is H.

% insert item I at N th position of  a list L to give resultant list

insert_ele( Val, 1, L, [Val|L]).

insert_ele(Val, N, [H|L1], [H|R]):-
	N1 is N-1,
	insert_ele( Val, N1, L1, R).

%delete Nth element from list

delete(1, [H|T], T).
delete( Pos, [H|T], [H|R]):-
	N1 is Pos-1,
	delete(N1, T, R).

% merge two  ordered lists

dmerge([],L2,L2).
dmerge(L1,[],L1).
dmerge([H1|T1],[H2|T2],[H1|T3]):- H1=<H2,
dmerge(T1, [H2|T2], T3).
dmerge([H1|T1],[H2|T2],[H2|T3]):- dmerge([H1|T1], T2, T3).
	
