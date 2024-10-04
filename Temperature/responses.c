#include "conversions.h"
#include "responses.h"

char* TemperatureCategory(float celcius) {
	if (celcius < 0) {
		return "Freezing";
	}
	else if (celcius <= 10) {
		return "Cold";
	}
	else if (celcius <= 25) {
		return "Comfortable";
	}
	else if (celcius <= 35) {
		return "Hot";
	}
	else {
		return "Extreme Heat";
	}
}

char* WeatherAdvisory(float celcius) {
	if (celcius < 0) {
		return "Stay indoors.";
	}
	else if (celcius <= 10) {
		return "Wear a jacket.";
	}
	else if (celcius <= 25) {
		return "You should feel comfortable outside.";
	}
	else if (celcius <= 35) {
		return "Drink water.";
	}
	else {
		return "Stay indoors and power the AC.";
	}
}

char TemperatureUnit(int tempType) {
	switch (tempType) {
	case 1:
		return 'C';
		break;
	case 2:
		return 'F';
		break;
	case 3:
		return 'K';
		break;
	default:
		return 'E';
		break;
	}
}

bool IsValidTemperature(float celcius) {
	return celciusToKelvin(celcius) >= 0;
}