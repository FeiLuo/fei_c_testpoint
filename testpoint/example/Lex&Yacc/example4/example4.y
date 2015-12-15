%{
#include <stdio.h>
#include <string.h>

typedef char* string;
#define YYSTYPE string

void yyerror(const char* str)
{
    fprintf(stderr, "error: %s\n", str);
}

/*
int yywrap()
{
    return 1;
}
*/
int main(void)
{
    yyparse();
    return 0;
}

%}

%token NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE

%%
commands: /* empty */
        | commands command
        ;

command:
        heat_switch
        |
        target_set
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
