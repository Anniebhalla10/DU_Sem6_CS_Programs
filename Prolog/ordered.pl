ordered( []) .
ordered( [_]) .
ordered( [X,Y|Z] ) :- X =< Y , ordered( [Y|Z] ) .