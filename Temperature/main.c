#include <stdio.h>
#include <stdbool.h>
#include "conversions.h"
#include "responses.h"

int main() {

	bool ranSuccessfully = false;
	while (!ranSuccessfully) {

		float temperature;
		int convertFrom, convertTo;

		printf("Choose a temperature (no units):\t");
		scanf("%f", &temperature);
		printf("Choose the current units (1) Celcius (2) Farenheit (3) Kelvin:\t");
		scanf("%d", &convertFrom);
		printf("Convert to (1) Celcius (2) Farenheit (3) Kelvin:\t");
		scanf("%d", &convertTo);

		bool flag1 = convertFrom < 1 || convertFrom > 3;
		bool flag2 = convertTo < 1 || convertFrom > 3;

		if (flag1 || flag2) {
			printf("Those are not valid values to convert to or from!");
		}
		else {
			
			float convertedTemperature, celciusTemperature;

			switch (convertFrom)
			{
				case 2:
					celciusTemperature = farenheitToCelcius(temperature);
					break;
				case 3:
					celciusTemperature = kelvinToCelcius(temperature);
					break;
				default:
					celciusTemperature = temperature;
					break;
			}
			
			if (convertFrom == convertTo) {
				printf("You can't convert a temperature to itself!");
				convertedTemperature = -999;
			} else if (convertFrom == 1 && convertTo == 2) {
				convertedTemperature = celciusToFarenheit(temperature);
			} else if (convertFrom == 1 && convertTo == 3) {
				convertedTemperature = celciusToKelvin(temperature);
			} else if (convertFrom == 2 && convertTo == 1) {
				convertedTemperature = farenheitToCelcius(temperature);
			} else if (convertFrom == 2 && convertTo == 3) {
				convertedTemperature = farenheitToKelvin(temperature);
			} else if (convertFrom == 3 && convertTo == 1) {
				convertedTemperature = kelvinToCelcius(temperature);
			} else {
				// If this line of code is reached, then (convertFrom == 3 && convertTo == 2) is true.
				convertedTemperature = kelvinToCelcius(temperature);
			}

			if (IsValidTemperature(celciusTemperature)) {
				printf("Converted Temperature: %f %c\nTemperature Category: %s\nWeather Advisory: %s\n",
					convertedTemperature,
					TemperatureUnit(convertTo),
					TemperatureCategory(celciusTemperature),
					WeatherAdvisory(celciusTemperature));
				ranSuccessfully = true;
			}
			else {
				printf("You can't have a temperature colder than absolute zero!\n");
			}
		}
	}

	return 1;
}