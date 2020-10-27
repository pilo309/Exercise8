#include <stdio.h>
#include "WeatherFunctions.h"


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