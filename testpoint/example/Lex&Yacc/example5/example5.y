%{
#include <stdio.h>
#include <string.h>

extern "C"{
void yyerror(const char* str);
extern int yylex(void);
}

%}

%token TOKHEAT TOKTARGET TOKTEMPERATURE

%union 
{
    float       floatval;
    void        *voidptr;
    int         integer;
    char        *string;
}

%token <integer>    STATE
%token <integer>    NUMBER


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
            if ($2)
                printf("\tHeat turned on\n");
            else
                printf("\tHeat turned off\n");
        }
        ;

target_set:
        TOKTARGET TOKTEMPERATURE NUMBER
        {
            printf("\tTemperature set to %d\n", $3);
        }
        ;

%%

void yyerror(const char* str)
{
    fprintf(stderr, "error: %s\n", str);
}

int main(int argc, char** argv)
{
    yyparse();
    return 0;
}


