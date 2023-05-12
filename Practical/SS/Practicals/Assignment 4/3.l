%{ #include<studio.h>

%}

%%

[a-z] printf("%c",yytext[0]-('a'-'A'));
0 return 0;

%%

int main(int argc[],char *argv[])
{
 yyin=fopen("shivam.txt", "r"); 
 yylex();
 return 0;
}
