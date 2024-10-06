#include <stdio.h>
#include <stdbool.h>
#include "conversions.h"
#include "responses.h"

int main() {

	bool ranSuccessfully = false;
	while (!ranSuccessfully) {

		float temperature;
		int convertFrom, convertTo;
		int c1, c2, c3 = 0;

		printf("Choose a temperature (no units):\t");
		c1 = scanf("%f", &temperature);

		// These if statements just prevent the program from getting more user input if the previous input is already invalid.
		if (c1) {
			printf("Choose the current units (1) Celcius (2) Farenheit (3) Kelvin:\t");
			c2 = scanf("%d", &convertFrom);
		}

		if (c1 && c2) {
			printf("Convert to (1) Celcius (2) Farenheit (3) Kelvin:\t");
			c3 = scanf("%d", &convertTo);
		}

		bool flag1 = convertFrom < 1 || convertFrom > 3;
		bool flag2 = convertTo < 1 || convertFrom > 3;

		if (!c1 || !c2 || !c3) {
			// This implies at least one calling of scanf recieved a bad value.
			printf("Those are not valid values that this program can work with!\n");

			/*
				After briefly researching scanf online, it seems the behavior for scanf is to leave
				any invalid input such that future scanf calls also run into the same problem

				The following code eats that value such that future scanf calls don't see it.
				I don't know what steps I have to take regarding memory stuff, as I don't think C has garbage collection
			*/
			char garbage;
			scanf("%s", &garbage);
		} else if (flag1 || flag2) {
			printf("Those are not valid values to convert to or from!\n");
		}
		else {
			
			float convertedTemperature, celciusTemperature;
			bool validConversion = true;

			// Find the temperature in one standard unit for the purpose of validating it and checking for "extreme values."
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
			
			// Find the temperature in the requested units or determine the conversion is invalid.
			if (convertFrom == convertTo) {
				/* 
					I would rather have simply acknowledged that the start and end of the conversion are the same,
					Tell the user, and just hand them back the temperature they inputted
					As if convertedTemperature = temperature
				*/
				validConversion = false;
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

			if (IsValidTemperature(celciusTemperature) && validConversion) {
				/* 
				  I chose 70 as the threshold for this statement by looking up the hottest
				  recorded temperature (Death Valley, 57 degrees C), rounding up to the next 10, then adding 10.
				  Similar logic applies to the lower extreme.
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
			else if (!IsValidTemperature(celciusTemperature) && validConversion) {
				printf("You can't have a temperature colder than absolute zero!\n");
			}
			else {
				// Stating that the conversion is invalid has greater priority to stating the temperature is.
				printf("There must be some form of conversion; the start and end units cannot be the same.\n");
			}
		}
	}

	return 1;
}