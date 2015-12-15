%{
#include <stdio.h>
#include "example5.tab.h"

extern "C"{
int yylex(void);
int yywrap(void);
}

%}
%%

[0-9]+          yylval.integer=atoi(yytext); return NUMBER;
heat            return TOKHEAT;
on|off          yylval.integer=!strcmp(yytext,"on"); return STATE;
target          return TOKTARGET;
temperature     return TOKTEMPERATURE;
\n              /* ignore end of line */;
[ \t]+          /* ignore whitespace */;

%%

int yywrap()
{
    return 1;
}

