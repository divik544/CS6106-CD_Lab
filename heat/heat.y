%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void yyerror(const char *str)
{
fprintf(stderr,"error: %s\n",str);
}

int yywrap()
{
return 1;
}

int main()
{
yyparse();
}
%}

%token TOKHEAT STATE TOKTARGET TOKTEMPERATURE NUMBER

%%
commands: /* empty */
	| commands command
	;
command: heat_switch
	| target_set
	;
heat_switch:
	TOKHEAT STATE
	{
		printf("\tHeat turned on or off\n");
	}
	;
target_set:
	TOKTARGET TOKTEMPERATURE NUMBER
	{
		printf("\tTemperature set\n");
	}
	;
%%

