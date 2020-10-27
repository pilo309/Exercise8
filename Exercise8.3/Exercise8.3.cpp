#include <stdio.h>


//exercise 8.3 oprette og bruge en struct
//
//opret et nyt projekt i visual studio. skriv koden for en struct kaldet dataset med
//følgende members:

//int winddirection
//double windspeed
//double temperature
//int pressure

//skriv nu en main funktion hvori du
//- opretter en variabel af typen dataset
//- skriver en værdi i hver member i din variabel
//- udskriver hver member i din variabel

int main(void)
{
	struct Dataset
	{
		double temperature_;
		double windspeed_;
		int pressure_;
		int winddirection_;

	};

	struct Dataset myDataset;

	myDataset.temperature_ = 100;
	myDataset.windspeed_ = 200;
	myDataset.pressure_ = 300;
	myDataset.winddirection_ = 400;

	printf_s("%lf, temperature\n", myDataset.temperature_);
	printf_s("%lf, windspeed\n", myDataset.windspeed_);
	printf_s("%d, pressure\n", myDataset.pressure_);
	printf_s("%d, winddirection\n", myDataset.winddirection_);

	printf_s("%lf", myDataset);
	return 0;
}