/* Author: Indrojyoti Mondal
// Date: 26th Jan 2018
// Email: indrojyoti.m15@iiits.in
// Roll No: 201501024

// lex program to eliminate unnecessary white spaces, comments
// and appropriately indent the given input c code.


-----------------To run-----------
$ lex <filename>.lex
$ gcc lex.yy.c -lfl
$ ./a.out <filename>.c

------------Details--------------
uncommented.c contains the c code without any comments, and unindented.
indented.c contains the indented uncommented c code.
output.c is the final c code.


*/

%{
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
%}
START "/*"
END "*/"
SIMPLE [^*]
SPACE [ \t\n]
COMPLEX "*"[^/]
%s newstate
%%
"//"(.*[ \t]*.*)*[\n]+    {printf("");}
{START}                    {yymore();BEGIN newstate;}
 <newstate>{SIMPLE}        {yymore();BEGIN newstate;}
 <newstate>{COMPLEX}      {yymore();BEGIN newstate;}
 <newstate>{SPACE}        {yymore();BEGIN newstate;}
 <newstate>{END}  {printf("");BEGIN 0;}

%%

main(int argc,char *argv[])
{

    yyin=fopen(argv[1],"r");
    yyout=fopen("uncommented.c","w+");
    yylex();
    fclose(yyout);
    system("indent -kr uncommented.c -o indented.c");
    // system wide 'indent' gnu package has to be installed
    system("cat indented.c >> output.c");
    yylex();
}