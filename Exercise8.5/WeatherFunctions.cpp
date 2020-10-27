#include "WeatherFunctions.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int getWindDirection()
{
	return rand() % 360;
}


double getTemperature()
{
	return ((rand() % 1200) - 600) / 9.99;
}


int getPressure()
{
	return (rand() % 100) + 900;
}


double getWindSpeed()
{
	return (rand() % 3333) / 41.2;
}


void printDataSet(struct dataset ds)
{
	printf_s("\nWinDir      = %d", ds.windDirection);
	printf_s("\nWindSpeed   = %.1f", ds.windSpeed);
	printf_s("\nTemperature = %.1f", ds.temperature);
	printf_s("\nPressure    = %d\n\n", ds.pressure);
}

void printDataSetP(struct dataset* ds)
{
	printf_s("\nWinDir      = %d", ds->windDirection);
	printf_s("\nWindSpeed   = %.1f", ds->windSpeed);
	printf_s("\nTemperature = %.1f", ds->temperature);
	printf_s("\nPressure    = %d\n\n", ds->pressure);
}