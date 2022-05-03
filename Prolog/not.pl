% to have not as a prdeicate we define it as

not(P):-
P,!,fail
;
true.

%it is a built in prolog predicate , it is also defined a s aprefix operator

% not(snake(X)) or not snake(X) are same
% not  can be denoted as \+ also
% they are defined a snegation as failure
% we can use not to replace cut and fail for lieks and different

likes(mary,X):- animal(X),
not snake(X).

different(X,Y):- not(X=Y).