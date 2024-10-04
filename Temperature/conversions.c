#include "conversions.h"
#include <stdbool.h>

float celciusToFarenheit(float celcius) {
	return 32 + (9 / 5) * celcius;
}

float celciusToKelvin(float celcius) {
	return celcius + 273.15;
}
float farenheitToCelcius(float farenheit) {
	return (5 / 9) * (farenheit - 32);
}
float farenheitToKelvin(float farenheit) {
	return celciusToKelvin(farenheitToCelcius(farenheit));
}

float kelvinToCelcius(float kelvin) {
	return kelvin - 273.15;
}

float kelvinToFarenheit(float kelvin) {
	return celciusToFarenheit(kelvinToCelcius(kelvin));
}