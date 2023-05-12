%{ #include<studio.h>
   
%}


%%
[1-9][0-9]{9} {printf("\nMobile Number Valid\n");}
  
.+ {printf("\nMobile Number Invalid\n");}

%%

int main(int argc[],char *argv[])
{
 printf("\nEnter Mobile Number : ");
 yylex();
  printf("\n");
 return 0;
}
