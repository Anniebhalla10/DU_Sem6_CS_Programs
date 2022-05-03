processfile:-
	read(Term),
	process(term).

process(end_of_file):- !.

process(Term):-
	treat(Term),
	processfile.