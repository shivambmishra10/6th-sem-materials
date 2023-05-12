%{
#include <stdio.h>
%}

%token NUMBER
%token MULTIPLY

%%

expression: NUMBER MULTIPLY NUMBER { printf("%d\n", $1 * $3); }
          ;

%%

int main() {
  yyparse();
  return 0;
}
