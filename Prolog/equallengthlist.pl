equallength([],[]):- !.

equallength([_|T1], [_|T2]):-
  equallength(T1,T2).