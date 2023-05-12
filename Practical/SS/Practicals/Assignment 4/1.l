%{ #include<studio.h>
int n_char=0;
int n_lines=0;
%}

%%
\n {++n_lines, ++n_char;}
. ++n_char;

%%

int main(int argc[],char *argv[])
{
 yyin=fopen("shivam.txt", "r"); 
 yylex();
 printf("n# of characters: %d",n_char);
 printf("\n");
 printf("n# of lines: %d",n_lines);
 printf("\n"); 
 return 0;
}
