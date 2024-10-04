#include <stdbool.h>
#ifndef Responses_H
#define Responses_H

char* TemperatureCategory(float celcius);
char* WeatherAdvisory(float celcius);
char TemperatureUnit(int tempType);
bool IsValidTemperature(float celcius);

#endif