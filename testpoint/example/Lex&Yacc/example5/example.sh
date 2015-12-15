name=example5
rm -rf $name *.c *.h
bison -d $name.y
flex $name.l
g++ lex.yy.c $name.tab.c -o $name

