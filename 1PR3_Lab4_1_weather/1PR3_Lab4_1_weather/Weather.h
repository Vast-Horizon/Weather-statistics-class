//Specification file
#ifndef WEATHER_H
#define WEATHER_H
#include <iostream>
class Weather
{
private:
	double total_Rain, high_temp, low_temp;
public:
	//default constructor
	Weather() { total_Rain = 0; high_temp = 0; low_temp = 0; }
	//constructor
	Weather(double, double, double);
	//mutator
	void setTotal(int t) { total_Rain = t; }
	void setHigh(int ht) { high_temp = ht; }
	void setLow(int lt) { low_temp = lt; }
	//accesser
	double getTotal()const { return total_Rain; }
	double getHigh()const { return high_temp;}
	double getLow()const { return low_temp; }
	//other function
	double averageTemp()const;
	//default destructor
	~Weather() {}
};
#endif
