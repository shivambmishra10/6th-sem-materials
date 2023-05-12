%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[01]+   { 
            int binary = strtol(yytext, NULL, 2);
            printf("%d\n", binary); 
        }
\n      { } 
.       { printf("Invalid input\n"); } 

%%

int main() {
    yylex();
    return 0;
}