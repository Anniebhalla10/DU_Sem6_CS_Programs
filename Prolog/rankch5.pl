beat( tom, jim). 
beat( ann, tom). 
beat( pat, jim). 

class( X, fighter) :-
beat( X, _ ), 
beat(_, X), !. 

class( X, winner) :-
beat( X, _ ),!. 

class( X, sportsman) :-
beat(_, X). 