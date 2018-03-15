#include<iostream>
#include<locale.h>
#include"Header.h"
#include<time.h>
#include<stdio.h>

using namespace std;


char *find_word(char *word, const char ch)
{
	char *start = word;
	while (*start) {
		if (*start == ch)
			return word;
		start++;
	}

	return 0;
}

int copyS(char *arr, char *arr1, int &r)
{
	if (r > strlen(arr))
	{
		r = strlen(arr);
		strcpy(arr1, arr);
	}
	else
	{
		for (int i = 0;i < r;i++)
		{
			*arr1 = *arr;
			arr++;
			arr1++;
		}
		*arr = '\0';
	}
	return 0;
}

static int cSymb(char *str, char symb)
{
	int count = 0;
	for (int i = 0;i < strlen(str);i++)
		if (*(str + i) == symb) count++;
	return count;
}

void repl2(char*str)
{
	int c = cSymb(str, '.');
	str = (char*)realloc(str, sizeof(char)*(strlen(str) + c));
	int n = 0, kon = 0, ws = 0;
	while (kon < strlen(str))
	{
		while (str[kon] != '.')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str) + 1;i >= kon;i--)
		{
			*(str + i) = *(str + i - 1);
		}
		*(str + kon) = ' ';
		kon = kon + 2;
	}
	printf("\n\n%s\n\n", str);
}

void repl(char*str)
{
	int c = cSymb(str, 'L');
	int n = 0, kon = 0, ws = 0;
	while (kon < strlen(str))
	{
		while (str[kon] != 'L')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str) + 1;i >= kon;i--)
		{
			*(str + i) = *(str + i );
		}
		*(str + kon) = 'l';
		kon = kon + 2;
	}
	printf("\n\n%s\n\n", str);
}
