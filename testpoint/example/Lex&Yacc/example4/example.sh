name=example4
rm -rf $name *.c *.h
bison -d $name.y
flex $name.l
cc -Wstrict-prototypes lex.yy.c $name.tab.c -o $name

