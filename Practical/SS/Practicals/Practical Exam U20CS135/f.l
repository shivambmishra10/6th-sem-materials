

%{
#include <stdio.h>
int yy = 0;   
%}

%%
a { yy++; }       
b { if (yy > 0) yy--; else yy = -1; }   
\n { if (yy == 0) printf("Valid string\n"); else printf("Invalid string\n"); yy = 0; } 
. { yy = -1; }    
%%

int main(void)
{
    yylex();
    return 0;
}
