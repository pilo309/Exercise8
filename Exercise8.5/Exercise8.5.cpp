#include <stdio.h>
#include "WeatherFunctions.h"
#include <stdlib.h>
#include <time.h>
#define SIZE 20

//Exercise 8.5 Array med structs
//Tilføj nedenstående 4 funktioner til dit program – skriv prototyperne i din header - fil
//(husk at inkludere <stdlib.h>) og implementeringen i din source 
//- fil(implementeringen kan du hente fra filen weather functions.cpp).
//
//int getWindDirection();
//double getTemperature();
//int getPressure();
//double getWindSpeed();
//
//I din main funktion skal du nu tilføje følgende :
//
//-Kalde srand(time(0)) et passende sted
//
//- Erklære et array med 20 structs af typen dataset
//
//- Fylde data ind i alle members i alle structs i dit array.Brug en for - løkke og
//funktionerne ovenfor til at generere data til de enkelte members i hver struct.
//
//- Udskrive alle structs i dit array.Brug en for - løkke og en af de 2 funktioner
//printDataSet() eller printDataSetP().
//
//Diskutér med en medstuderende hvad fordelen er ved at gemme vejrdata i et array
//af structs.

int main(void)
{


	srand(time(0));

		struct dataset data[SIZE];

		for (size_t i = 0; i < SIZE; i++)		//lave for loop der fylder hvert member i dataset array
		{
			data[i].pressure = getPressure();
			data[i].temperature = getTemperature();
			data[i].windDirection = getWindDirection();
			data[i].windSpeed = getWindSpeed();
		}

		for (size_t i = 0; i < SIZE; i++)
		printDataSet(data[i]);

	return 0;
}