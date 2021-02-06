//Implementation file
#include "Weather.h"
Weather::Weather(double ht, double lt, double t) {
	total_Rain=t, high_temp=ht, low_temp=lt;
}
double Weather::averageTemp()const {
	double avgTemp = (high_temp + low_temp) / 2;
	return avgTemp;
}