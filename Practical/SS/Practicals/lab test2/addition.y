%{
#include <stdio.h>
%}

%token NUMBER
%token PLUS

%%

expression: NUMBER PLUS NUMBER { printf("%d\n", $1 + $3); }
          ;

%%

int main() {
  yyparse();
  return 0;
}
