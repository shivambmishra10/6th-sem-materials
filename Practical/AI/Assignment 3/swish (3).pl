% Define the predicate to find the maximum of three numbers
max3(A, B, C, Max) :- 
    Max is max(max(A, B), C).

% Define the predicate to find the minimum of three numbers
min3(A, B, C, Min) :-
    Min is min(min(A, B), C).

% Define the main predicate to find the maximum and minimum
find_min_max :-
    write('Enter first number: '),
    read(A),
    write('Enter second number: '),
    read(B),
    write('Enter third number: '),
    read(C),
    max3(A, B, C, Max),
    min3(A, B, C, Min),
    write('Maximum: '),
    write(Max),
    nl,
    write('Minimum: '),
    write(Min).
