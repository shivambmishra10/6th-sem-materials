% Define the predicate to determine if a vehicle number is odd or even
odd_even(VehicleNumber, Result) :-
    (0 is VehicleNumber mod 2 -> Result = even;
     Result = odd).

% Define the main predicate to check the eligibility of a vehicle
eligible_days :-
    write('Whats ur vehicle number: '),
   	read(VehicleNumber),
    odd_even(VehicleNumber, Result),
    (Result = odd -> write('Eligible days: Monday, Wednesday, Friday');
     Result = even -> write('Eligible days: Tuesday, Thursday, Saturday');
     write('Eligible days: Sunday')).


