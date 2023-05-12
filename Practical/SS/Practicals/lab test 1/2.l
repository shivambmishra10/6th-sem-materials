%{ #include<studio.h>
int cnt=0;
%}

%%
"-" cnt++;

. printf("Invalid");

%%

int main(int argc[],char *argv[])
{

 yylex();
 if(cnt==3)
 printf("DECREMENT MINUS");
 else if(cnt==2)
 printf("DECREMENT");
 else if(cnt==1)
 printf("MINUS");

 
 return 0;
}