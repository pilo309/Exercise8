#pragma once

struct dataset
{
	int windDirection;
	double windSpeed;
	double temperature;
	int pressure;
};


void printDataSet(struct dataset ds);

void printDataSetP(struct dataset* ds);