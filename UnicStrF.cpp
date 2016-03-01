#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>


struct StrList
{
	char str[256];
	StrList *pNext;
};


void addNew(StrList *&pFirst, StrList *&pLast, StrList *p)
{
	if (pFirst == 0)
	{
		p->pNext = pFirst;
		pFirst = p;
		pLast = p;
	}
	else
	{
		p->pNext = 0;
		pLast->pNext = p;
		pLast = p;
	}
}


StrList *pFirst1 = 0, *pLast1 = 0, *pFirst2 = 0, *pLast2 = 0, *p, *pbuf;


int main()
{
	int ch, n;
	char f1[64] = "", f2[64] = "", str[256] = "";
	printf("Enter name of file 1: ");
	fflush(stdin);
	gets_s(f1);
	printf("Enter name of file 2: ");
	fflush(stdin);
	gets_s(f2);
	FILE *pFile;


	pFile = fopen(f1, "r");
	if (pFile == NULL)
	{
		printf("Error: didn't find file 1\n");
		system("pause");
		return 1;
	}
	fflush(pFile);
	while (fgets(str, 255, pFile) != NULL)
	{
		fflush(pFile);
		p = new StrList;
		strcpy(p->str, str);
		addNew(pFirst1, pLast1, p);
	}
	fclose(pFile);


	pFile = fopen(f2, "r");
	if (pFile == NULL)
	{
		printf("Error: didn't find file 2\n");
		system("pause");
		return 1;
	}
	fflush(pFile);
	while (fgets(str, 255, pFile) != NULL)
	{
		fflush(pFile);
		p = new StrList;
		strcpy(p->str, str);
		addNew(pFirst2, pLast2, p);
	}
	fclose(pFile);


	strcat(pLast1->str, "\n");
	strcat(pLast2->str, "\n");


	p = pFirst1;
	n = 1;
	while (p != 0)
	{
		pbuf = pFirst2;
		ch = 0;
		while (pbuf != 0)
		{
			if (strcmp(p->str, pbuf->str) == 0) ch = 1;
			if (ch == 1) break;
			pbuf = pbuf->pNext;
		}
		if (ch == 0) printf("%s %d %s", f1, n, p->str);
		p = p->pNext;
		n += 1;
	}


	p = pFirst2;
	n = 1;
	while (p != 0)
	{
		pbuf = pFirst1;
		ch = 0;
		while (pbuf != 0)
		{
			if (strcmp(p->str, pbuf->str) == 0) ch = 1;
			if (ch == 1) break;
			pbuf = pbuf->pNext;
		}
		if (ch == 0) printf("%s %d %s", f2, n, p->str);
		p = p->pNext;
		n += 1;
	}


	system("pause");
	return 0;
}