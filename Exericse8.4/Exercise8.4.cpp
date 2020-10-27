#include <stdio.h>
#include "WeatherFunctions.h"

//Exercise 8.4 Structs som funktions - parametre
//
//Tilføj en header - fil med 2 funktioner med disse prototyper
//
//void printDataSet(struct dataset ds);
//void printDataSetP(struct dataset* ds);
//
//
//Tilføj så en source - fil med implementeringen af de to funktioner.
//
//I din main funktion skal du nu tilføje følgende :
//
//-Opret 2 struct - variable af typen dataset
//
//- Skrie en værdi i hver member i de to struct - variable
//
//- Udskriv data for de to struct - variable, den ene vha.funktionen 
//printDataSet() og den anden vha.funktionen printDataSetP().

#include "WeatherFunctions.h"


int main()
{
	struct dataset ds1;

	ds1.windDirection = 201;
	ds1.windSpeed = 32.88;
	ds1.temperature = 23.99;
	ds1.pressure = 877;

	printDataSet(ds1);
	printDataSetP(&ds1);

	return 0;
}