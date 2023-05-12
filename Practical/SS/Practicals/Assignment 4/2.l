%{ #include<studio.h>
int vowels=0;
int consonants=0;
%}

%%

[aeiouAEIOU] ++vowels;
[a-zA-Z] ++consonants;

%%

int main(int argc[],char *argv[])
{
 yyin=fopen("shivam.txt", "r"); 
 yylex();
 printf("n# of vowels: %d",vowels);
 printf("\n");
 printf("n# of consonants: %d",consonants);
 printf("\n"); 
 return 0;
}
