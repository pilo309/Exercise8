#include "code functions.h"
#include <stdio.h>
#include <string.h>

void createCode(char codeAlias[])
{
	int ascii;

	srand(time(0));

	for (size_t index = 0; index < CODE_SIZE; index++)
	{
		ascii = (rand() % 75 + 48);

		// if ascii number is NOT a letter or digit (check ASCII table)
		if (57 < ascii && ascii < 65 || 90 < ascii && ascii < 97)
			index--;
		else
			codeAlias[index] = ascii;
	}

	codeAlias[CODE_SIZE] = '\0';
}


int checkCode(char correctCodeAlias[], char codeToCheckAlias[])
{
	return strcmp(correctCodeAlias, codeToCheckAlias);
	
}


int changeCode(char currentCodeAlias[], char newCodeAlias[])
{
	if (strlen(currentCodeAlias) == strlen(newCodeAlias));
	{
		for (size_t index = 0; index < CODE_SIZE; index++)
		{

			if (currentCodeAlias[index] != newCodeAlias[index])
			{
				return 1;
			}


		}
		return 0;
	}

	{
		return 1;
	}

}