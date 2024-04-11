#include<stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX_ERR 5

static const char* p[] = { "",
" zle dane: ",
" otwarcie pliku: ",
" pamieci: ",
" Usage: ",
" nieznany: ",
};
void error(int nr, const char* str)
{
	int k;
	k = nr >= MAX_ERR ? MAX_ERR : nr;
	fprintf(stderr, "Blad(%d) - %s %s\n", nr, p[k], str);
	system("pause");
	exit(nr);
}