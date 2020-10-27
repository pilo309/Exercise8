#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <RaspberryDLL.h>
#include <Windows.h>
#include <conio.h>
#include "code functions.h"

//Exercise 8.2 Adgangskontrol system – iteration 1
//Opret et nyt Raspberry Pi projekt i Visual Studio.Tilføj modulet ”code functions” fra
//
//Exercise 8.1 til projektet(NB.Husk, at du skal kopiere filerne til dit projekt inden du
//	anvender ”Add Existing Item” i Visual Studio).
//
//	Sammen med denne øvelse ligger filen ”access control system.cpp”.
//	Heri finder du en del af programmet(main) til adgangskontrol systemet.
//	Tilføj filen til dit Visual Studio projekt(husk igen at kopiere den til projektmappen
//		inden du tilføjer den med ”Add Existing Item”).
//
//	Skriv programmet(main) færdigt, så adgangskontrol systemet kommer til at
//	fungere som beskrevet ovenfor.
//	NB!Iteration 2 finder du som en ekstraopgave i Exercise 8.6.

//Ekstraopgave
//
//Exercise 8.6 Adgangskontrol system – iteration 2
//
//Det skal selvfølgelig være muligt for en person, at ændre den ”udleverede” kode til
//en kode han / hun selv vælger.Tilføj denne mulighed til dit program fra Exercise 8.2
//(kig på funktionerne i modulet ”code functions” fra Exercise 8.1 ).


int main()
{
	if (!Open())
	{
		printf_s("Error with connection\n");
		exit(1);
	}

	printf_s("Connected to Raspberry Pi\n");

	char userCode[CODE_SIZE + 1], codeFromKeyboard[CODE_SIZE + 1];
	int codeOkay;
	char userinput;

	createCode(userCode);

	printf_s("\nDin kode er %s\n\nTryk 'a' for at aktivere systemet, og 'k' for at ændre kode\n", userCode);
	do
	{
		do
		{

			userinput = getch();

		} while (userinput != 'a' && userinput != 'k');

		char Kode2[CODE_SIZE];
		char Kode3[CODE_SIZE];
		int check;

		if (userinput = 'k')
		{
			printf_s("\nIndtast ny kode paa max 8 tegn\n");
			Kode2 = getch();		//fgets har mellemrum med, (der hvor det lægges hen, maks størrelse, keyboard input)

			printf_s("\nIndtast ny kode paa 8 tegn igen\n");  //definere anden kode
			Kode3 = getch();

			check = checkCode(Kode3, Kode2);           //definere vores check som værdien vi får ud fra funktionen
		}
		if (check == 1)
		{
			printf_s(" Check = %d, ergo er koderne ens.\n", check);

			userCode = Kode3;

		}

		else
		{
			printf_s(" Check = %d, ergo er koderne IKKE ens, indtast koderne igen!", check);
		}

	} while (userinput != 'a')

	do
	{
		codeOkay = 0;					// Reset codeOkay
		ledOn(6);						// Tænd rød LED
		system("cls");					// Slet skærmen
		printf_s("%s", "LOCKED\n\n");

		printf_s("%s", "Tast din kode for at l\x86se d\x9Bren op, - eller tast + for at lukke systemet ned\n\n");

		// Vent så længe der ikke trykkes på PC tastatur og der ikke trykkes på "udknap" (key P1 på RP'en)
		while (!_kbhit() && !keyPressed(P1)) //hvis der trykkes på en knap bliver while (false)
		{
			// Her skal IKKE stå noget kode - programmet "venter" på en hændelse ("tom" while-loop)
		}

		// Der blev trykket på PC tastaturet
		if (_kbhit())
		{
			// Indlæs karakteren og gem på 1. plads i codeFromKeyboard[]
			for (size_t i = 0; i < CODE_SIZE; i++)
			{
				codeFromKeyboard[i] = _getch();

				if (codeFromKeyboard[i] != '+')
					printf_s("* ");

				else
					break;
			}

			codeFromKeyboard[CODE_SIZE] = '\0';


			// Hvis den indlæste karakter IKKE er '+'
			// Indlæs de næste 7 karakterer - EN ad gangen og gem løbende i codeFromKeyboard[]
			// HVER GANG der er indlæst en karakter udskrives en '*' på skærmen
			// Gem til sidst '\0' på sidste plads i codeFromKeyboard[]


			// Kald checkCode() og gem svar i variablen codeOkay
			// Hvis koden er forkert
			// Udskriv fejlmeddellelse og vent 5 sek

			codeOkay = checkCode(userCode, codeFromKeyboard); //returnerer kode 1 hvis de er equal

			if (codeOkay == 0)
			{
				printf_s("You entered a wrong code.");
				Wait(5000);
			}
		}
		// Der blev trykket på "udknap"
		else if (keyPressed(P1) == 1)
			codeOkay = 1;

		// Den indtastede kode er korrekt eller der blev trykket på "udknap"
		if (codeOkay == 1)
		{
			printf_s("\nUNLOCKED");

			ledOff(6);

			for (size_t i = 1; i <= 20; i++)			//får led til at blinke ved åbning
			{
				ledOn(5);
				ledOff(5);
				Wait(500);
			}

			codeOkay = 0;				//
			ledOff(5);
			ledOn(6);
			// Her skrives den del af programmet som låser "døren" op/låser "døren" og styrer LED'erne
			// NB! "Døren skal automatisk låses igen efter 10 sekunder (se opgaveteksten)
		}

	} while (codeFromKeyboard[0] != '+');

	ledOff(6);

	return 0;
}