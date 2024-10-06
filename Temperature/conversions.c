#include "conversions.h"
#include <stdbool.h>

// A lot of this is just raw math; I don't know what to tell you.

float celciusToFarenheit(float celcius) {
	// I don't know how to express 5/9 in a more concise manner, as 5 / 9 itself seems to be rounded.
	return 32 + (9.0 / 5.0) * celcius;
}

float celciusToKelvin(float celcius) {
	return celcius + 273.15;
}
float farenheitToCelcius(float farenheit) {
	return (5.0 / 9.0) * (farenheit - 32);
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