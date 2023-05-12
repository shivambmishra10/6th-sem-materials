%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}

%token DIGIT
%token END

%%

input: binary_num END {
            printf("%s in binary = %d in decimal\n", $1, binaryToDecimal($1));
        }
     | END
     ;

binary_num: DIGIT {
            $$ = $1 - '0';
        }
          | binary_num DIGIT {
            $$ = $1 * 2 + $2 - '0';
        }
          ;

%%

int binaryToDecimal(char* binary) {
    int len = strlen(binary);
    int decimal = 0;
    for (int i = 0; i < len; i++) {
        decimal += (binary[i] - '0') * pow(2, len - 1 - i);
    }
    return decimal;
}

int yylex() {
    static int last_token = 0;
    int token = getchar();
    if (token == '0' || token == '1') {
        return token;
    }
    if (last_token == '0' || last_token == '1') {
        ungetc(token, stdin);
        return END;
    }
    last_token = token;
    return token;
}

int yyerror(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}
