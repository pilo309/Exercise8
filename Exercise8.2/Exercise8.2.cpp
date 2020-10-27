#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <RaspberryDLL.h>
#include <Windows.h>
#include <conio.h>
#include "code_functions.h"

//Exercise 8.2 Adgangskontrol system � iteration 1
//Opret et nyt Raspberry Pi projekt i Visual Studio.Tilf�j modulet �code functions� fra
//
//Exercise 8.1 til projektet(NB.Husk, at du skal kopiere filerne til dit projekt inden du
//	anvender �Add Existing Item� i Visual Studio).
//
//	Sammen med denne �velse ligger filen �access control system.cpp�.
//	Heri finder du en del af programmet(main) til adgangskontrol systemet.
//	Tilf�j filen til dit Visual Studio projekt(husk igen at kopiere den til projektmappen
//		inden du tilf�jer den med �Add Existing Item�).
//
//	Skriv programmet(main) f�rdigt, s� adgangskontrol systemet kommer til at
//	fungere som beskrevet ovenfor.
//	NB!Iteration 2 finder du som en ekstraopgave i Exercise 8.6.


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

	createCode(userCode);

	printf_s("\nDin kode er %s\n\nTryk en tast for at aktivere systemet\n", userCode);

	getch();

	do
	{
		codeOkay = 0;					// Reset codeOkay
		ledOn(6);						// T�nd r�d LED
		system("cls");					// Slet sk�rmen
		printf_s("%s", "LOCKED\n\n");

		printf_s("%s", "Tast din kode for at l\x86se d\x9Bren op - eller tast + for at lukke systemet ned\n\n");

		// Vent s� l�nge der ikke trykkes p� PC tastatur og der ikke trykkes p� "udknap" (key P1 p� RP'en)
		while (!_kbhit() && !keyPressed(P1)) //hvis der trykkes p� en knap bliver while (false)
		{
			// Her skal IKKE st� noget kode - programmet "venter" p� en h�ndelse ("tom" while-loop)
		}

		// Der blev trykket p� PC tastaturet
		if (_kbhit())
		{
			// Indl�s karakteren og gem p� 1. plads i codeFromKeyboard[]
			for (size_t i = 0; i < CODE_SIZE; i++)
			{
				codeFromKeyboard[i] = _getch();

				if (codeFromKeyboard[i] != '+')
					printf_s("* ");

				else
					break;
			}
			
			codeFromKeyboard[CODE_SIZE] = '\0';


			// Hvis den indl�ste karakter IKKE er '+'
			// Indl�s de n�ste 7 karakterer - EN ad gangen og gem l�bende i codeFromKeyboard[]
			// HVER GANG der er indl�st en karakter udskrives en '*' p� sk�rmen
			// Gem til sidst '\0' p� sidste plads i codeFromKeyboard[]


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
		// Der blev trykket p� "udknap"
		else if (keyPressed(P1) == 1)
			codeOkay = 1;

		// Den indtastede kode er korrekt eller der blev trykket p� "udknap"
		if (codeOkay == 1)
		{
			printf_s("\nUNLOCKED");

			ledOff(6);

			for (size_t i = 1; i <= 20; i++)			//f�r led til at blinke ved �bning
			{
				ledOn(5);
				ledOff(5);
				Wait(500);
			}

			codeOkay = 0;
			ledOff(5);
			ledOn(6);
			// Her skrives den del af programmet som l�ser "d�ren" op/l�ser "d�ren" og styrer LED'erne
			// NB! "D�ren skal automatisk l�ses igen efter 10 sekunder (se opgaveteksten)
		}

	} while (codeFromKeyboard[0] != '+');

	ledOff(6);

	return 0;
}