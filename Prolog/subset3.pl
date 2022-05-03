subset([], []).

subset(Set, Subset) :-
    del(_ ,[_|Subset] ,Set),
    subset(Subset, _).