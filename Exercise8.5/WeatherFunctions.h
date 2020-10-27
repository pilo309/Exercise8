#pragma once

struct dataset
{
	int windDirection;
	double windSpeed;
	double temperature;
	int pressure;
};

int getWindDirection(void);
double getTemperature(void);
int getPressure(void);
double getWindSpeed(void);

void printDataSet(struct dataset ds);

void printDataSetP(struct dataset* ds);
