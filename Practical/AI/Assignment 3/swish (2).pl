% Define the predicate to perform addition
add(A, B, C) :- C is A + B.

% Define the predicate to perform subtraction
sub(A, B, C) :- C is A - B.

% Define the predicate to perform multiplication
mul(A, B, C) :- C is A * B.

% Define the predicate to perform division
div(A, B, C) :- C is A / B.

% Define the main predicate to perform the calculator operations
calculator :- 
    write('Enter first number: '),
    read(A),
    write('Enter second number: '),
    read(B),
    write('Enter operation (add, sub, mul, div): '),
    read(OP),
    (OP = add -> add(A, B, C); 
     OP = sub -> sub(A, B, C);
     OP = mul -> mul(A, B, C);
     OP = div -> div(A, B, C)),
    write('Result: '),
    write(C).
