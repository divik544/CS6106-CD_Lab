%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char *msg)
{
	printf("\nSome error\n");
}

extern int yylex();

int yywrap()
{
	return 1;
}
int main()
{
	yyparse();
	return 0;
}
%}

%union {
	float f;
}
%token <f> NUM

%type <f> E T F

%%

S	: E 			{printf("%f\n",$1);}
	;
E 	: E '+' T 	{$$ = $1 + $3;}
	| E '-' T 	{$$ = $1 - $3;}
	| T 		{$$ = $1;}
	;
T 	: T '*' F 	{$$ = $1 * $3;}
	| T '/' F 	{$$ = $1 / $3;}
	| F 		{$$ = $1;}
	;
F	: NUM 		{$$ = $1;}
	;
%%