

#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 0
#define MAXWORDLEN 15

int main()
{
    int i, j;
    int c, wl, state, maxval;
    int length[MAXWORDLEN + 1];

    for (i = 0; i <= MAXWORDLEN; ++i)
	length[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\t' || c == '\n') {
	    if (state == IN) {
		if (wl <= MAXWORDLEN)
		    length[wl - 1] += 1;
		else
		    length[MAXWORDLEN] += 1;
		state = OUT;
	    }
	} else {
	    if (state == OUT) {
		wl = 0;
		state = IN;
	    }
	    wl += 1;
	}
    }



    printf("Horizontal histogram\n\n");

    for (i = 0; i <= MAXWORDLEN; ++i) {
	if (i != MAXWORDLEN)
	    printf(" %2d: ", i + 1);
	else
	    printf(">%d: ", MAXWORDLEN);

	for (j = 0; j < length[i]; ++j)
	    putchar('#');
	putchar('\n');
    }



    printf("\nVertical histogram\n\n");


    maxval = 0;
    for (i = 0; i <= MAXWORDLEN; ++i)
	if (length[i] > maxval)
	    maxval = length[i];


    for (i = 0; i < maxval; ++i) {
	printf(" %2d |", maxval - i);
	for (j = 0; j <= MAXWORDLEN; ++j) {
	    if (length[j] >= maxval - i)
		printf("  #");
	    else
		printf("   ");
	}
	printf("\n");
    }


    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
	printf("---");
    printf("-\n");


    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
	if (i != MAXWORDLEN)
	    printf(" %2d", i + 1);
	else
	    printf(" %2d>", i);
    printf("\n");
    return 0;


#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 0
#define MAXWORDLEN 15

int main()
{
    int i, j;
    int c, wl, state, maxval;
    int length[MAXWORDLEN + 1];

    for (i = 0; i <= MAXWORDLEN; ++i)
	length[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\t' || c == '\n') {
	    if (state == IN) {
		if (wl <= MAXWORDLEN)
		    length[wl - 1] += 1;
		else
		    length[MAXWORDLEN] += 1;
		state = OUT;
	    }
	} else {
	    if (state == OUT) {
		wl = 0;
		state = IN;
	    }
	    wl += 1;
	}
    }



    printf("Horizontal histogram\n\n");

    for (i = 0; i <= MAXWORDLEN; ++i) {
	if (i != MAXWORDLEN)
	    printf(" %2d: ", i + 1);
	else
	    printf(">%d: ", MAXWORDLEN);

	for (j = 0; j < length[i]; ++j)
	    putchar('#');
	putchar('\n');
    }



    printf("\nVertical histogram\n\n");


    maxval = 0;
    for (i = 0; i <= MAXWORDLEN; ++i)
	if (length[i] > maxval)
	    maxval = length[i];


    for (i = 0; i < maxval; ++i) {
	printf(" %2d |", maxval - i);
	for (j = 0; j <= MAXWORDLEN; ++j) {
	    if (length[j] >= maxval - i)
		printf("  #");
	    else
		printf("   ");
	}
	printf("\n");
    }


    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
	printf("---");
    printf("-\n");


    printf("     ");
    for (i = 0; i <= MAXWORDLEN; ++i)
	if (i != MAXWORDLEN)
	    printf(" %2d", i + 1);
	else
	    printf(" %2d>", i);
    printf("\n");
    return 0;


#include <stdio.h>

#define TRUE  1
#define FALSE 0
#define PRINTLEN 80

int get_line(char line[], int maxline);


int main()
{
    char line[PRINTLEN + 1];
    int len, longline;

    longline = FALSE;
    while ((len = get_line(line, PRINTLEN + 1)) > 0) {
	if (line[len - 1] != '\n') {

	    printf("%s", line);
	    longline = TRUE;
	} else if (longline) {

	    printf("%s", line);
	    longline = FALSE;
	}
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}


#include <stdio.h>

#define TRUE  1
#define FALSE 0
#define PRINTLEN 80

int get_line(char line[], int maxline);


int main()
{
    char line[PRINTLEN + 1];
    int len, longline;

    longline = FALSE;
    while ((len = get_line(line, PRINTLEN + 1)) > 0) {
	if (line[len - 1] != '\n') {

	    printf("%s", line);
	    longline = TRUE;
	} else if (longline) {

	    printf("%s", line);
	    longline = FALSE;
	}
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}
