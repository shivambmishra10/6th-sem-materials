%{
#include <stdio.h>

int pos_count = 0, neg_count = 0, frac_count = 0;
%}

%%

[+-]?[0-9]+                 { 
                                if(yytext[0] == '-')
                                    neg_count++;
                                else
                                    pos_count++;
                            }

[+-]?[0-9]+\.[0-9]+         { 
                                if(yytext[0] == '-')
                                    neg_count++;
                                else
                                    pos_count++;
                                frac_count++;
                            }

.                          

%%

int main(void)
{
    yylex();
    printf("Positive numbers: %d\n", pos_count);
    printf("Negative numbers: %d\n", neg_count);
    printf("Fractional numbers: %d\n", frac_count);
    return 0;
}
