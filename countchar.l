%{
#include<stdio.h>
#include<stdlib.h>
int cno=0,wno=0,lno=0;
%}
character	[a-z]
digit	[0-9]
word ({character}|{digit})+[^({character}|{digit})]
line \n
%%
{line}	{lno++;}
{word}	{wno++;}
{character}	{cno++;}
{digit}	{cno++;}
%%
int yywrap(void)
{
return 1;
}
void main()
{
yylex();
printf("No of character%d",cno);
printf("No of words%d",wno);
printf("No of lines%d",lno);
return;
}
