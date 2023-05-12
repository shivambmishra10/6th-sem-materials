%{ #include<studio.h>
int n_digits=0;
%}

%%
[0-9] {++n_digits;}
. printf("Invalid");

%%

int main(int argc[],char *argv[])
{
 yyin=fopen("shivam.txt", "r"); 
 yylex();
 printf("n# of n_digits: %d",n_digits);
 printf("\n");
 
 return 0;
}