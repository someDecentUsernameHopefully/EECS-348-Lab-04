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
			printf("Those are not valid values to convert to or from!\n");
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
				printf("There must be some form of conversion; the start and end units cannot be the same.");
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
				convertedTemperature = kelvinToFarenheit(temperature);
			}

			if (IsValidTemperature(celciusTemperature)) {
				/* 
				  I chose 70 as the threshold for this statement by looking up the hottest
				  recorded temperature (Death Valley, 57 degrees C), rounding up to the next 10, then adding 10.
				*/
				if (celciusTemperature > 70) {
					printf("\nThe temperature inputted is quite high; did you use the wrong units or accidentally add an extra zero?\n");
				}
				else if (celciusTemperature < -100) {
					printf("\nThe temperature inputted is quite low; did you use the wrong units or accidentally add a negative sign?\n");
				}
				printf("\nConverted Temperature: %f %c\nTemperature Category: %s\nWeather Advisory: %s\n",
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