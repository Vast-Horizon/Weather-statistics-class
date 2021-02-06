#include <iostream>
#include <fstream>
#include <iomanip>
#include "Weather.h"

using namespace std;
int main() {
	//creat 12 month objects
	Weather obj[12];
	double rain, hightemp, lowtemp;
	int i = 0;
	//month names
	string monthList[12] = { "Jan.", "Feb.", "Mar.", "Apr.", "May", "June",
					"July", "Aug.", "Sept.", "Oct.", "Nov.", "Dec." };
	//file object
	fstream input;
	//open the file
	input.open("weather.txt", ios::in);
	if (input.fail()) {
		cout << "Cannot open the file" << endl;
	}
	else {
		
		while (!input.eof()) {
			//read the file
			input >> hightemp >> lowtemp >> rain;
			//store the data into the weather object
			obj[i] = Weather(hightemp, lowtemp, rain);
			i++;
		}
		//output the file data
		cout << "Month\t High-Temp\t Low-Temp\t Rainfall" << endl;
		for (int j = 0; j < 12; j++) {
			cout << left <<setw(12)<<monthList[j] << setw(15)<<obj[j].getHigh() <<setw(16)
				<< obj[j].getLow() 
				<< obj[j].getTotal() << endl;
		}
		input.close();
	}
	int   HighIndex, LowIndex;
	double avgTotalT, avgRainfall, TotalT = 0, TotalRainfall = 0, maxTemp = 0, miniTemp = 1000;


	for (int i = 0; i < 12; i++) {
		//find the total rainfall value
		TotalRainfall += obj[i].getTotal();
		//find the highest temperature
		if (obj[i].getHigh() > maxTemp)
		{
			maxTemp = obj[i].getHigh();
			HighIndex = i;
		}
		//find the lowest temperature
		if (obj[i].getLow()< miniTemp)
		{
			miniTemp = obj[i].getLow();
			LowIndex = i;
		}
		//find the total average temperature
		TotalT += obj[i].averageTemp();
	}
	//the average of all average temperature and rainfall
	avgTotalT = TotalT / 12.0;
	avgRainfall = TotalRainfall / 12.0;
	//output
	cout << "\n*******************************************************\n";
	cout << "The total rainfall for the year is " << TotalRainfall << endl;
	cout << "The average monthly rainfall for the year is " << avgRainfall << endl;
	cout << "The average of all the monthly average temperature is " <<setprecision(1)<<fixed<< avgTotalT << endl;
	cout << "The highest temperature for the year occurs in " << monthList[HighIndex]
		<< ", which is " << maxTemp << endl;
	cout << "The lowest temperature for the year occurs in " << monthList[LowIndex]
		<< ", which is " << miniTemp << endl;
	system("pause");
	return 0;
}