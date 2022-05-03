classNumber(Number, positive) :-
    Number > 0.
classNumber(0, zero).
classNumber(Number, negative) :-
    Number < 0.

% Improvement for the procedure
classNumber1(Number, positive) :-
    Number > 0, !.
classNumber1(0, zero) :-
    !.
classNumber1(_, negative).




split([], [], []).
% recursive line
split([H|T], L1, [H|T2]) :-
    classNumber(H, negative), % Remember to use exist helper!
    split(T, L1, T2), !.
split([H|T], [H|T1], L2) :-
    split(T, T1, L2).

% without cut
% base line
split1([], [], []).
% recursive line
split1([H|T], [H|T1], L2) :-
    not(classNumber(H, negative)), % Remember to use exist helper!
    split(T, T1, L2).
split1([H|T], L1, [H|T2]) :-
    classNumber(H, negative), % Remember to use exist helper!
    split(T, L1, T2).