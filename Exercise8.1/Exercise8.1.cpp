#include <stdio.h>
#include <string.h>
#include "code functions.h"
#define ARRAY_SIZE 9

//Exercise 8.1 Forbedring af modulet ”Code functions”
//
//Brug noget af det du lige har lært om C strenge(biblioteks funktioner) til at gøre
//koden for funktionen checkCode() (fra Exercise 6.3) meget simplere(Hint 8A).

//Hint 8A: Er der en funktionen i <string.h> der kan sammenligne to
//tekststrenge ?

//Kan du bruge den i checkCode().
//Hvad gør det ved din funktion checkCode() ?

int main()
{

	char Kode1[ARRAY_SIZE];
	char Kode2[ARRAY_SIZE];
	char Kode3[ARRAY_SIZE];
	int check;
	int newCode;

	printf_s("Indtast den gamle kode paa\n");
	fgets(Kode3, ARRAY_SIZE, stdin);

	printf_s("\nIndtast ny kode paa max 8 tegn\n");
	fgets(Kode1, ARRAY_SIZE, stdin);			//fgets har mellemrum med, (der hvor det lægges hen, maks størrelse, keyboard input)

	printf_s("\nIndtast ny kode paa 8 tegn igen\n");  //definere anden kode
	fgets(Kode2, ARRAY_SIZE, stdin);

	check = checkCode(Kode1, Kode2);           //definere vores check som værdien vi får ud fra funktionen

	if (check == 0)
	{
		printf_s(" Check = %d, ergo er koderne ens.\n", check);

		newCode = changeCode(Kode3, Kode2);

	}

	else
	{
		printf_s(" Check = %d, ergo er koderne IKKE ens, indtast koderne igen!", check);
	}



	return 0;
}	