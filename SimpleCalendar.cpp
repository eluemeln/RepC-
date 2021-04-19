#include<iostream> 
#include<cmath> 
#include<fstream>
using namespace std;
int main()
{
	int numberOfDays, beginingDay, year, counter = 0;

	cout << "What year would you like to see a calendar for? \n";
	cin >> year;

	cout << "Enter the first day of the month. 0 for Sunday ... 6 for Saturday\n";
	cin >> beginingDay;

	ofstream myfile;
	myfile.open("calendar.txt");

	while (counter < 12)//This loop displays calender
	{
		switch (counter)//sets the month and total days per month
		{
		case 0:
			myfile << "January \n";
			numberOfDays = 31;
			break;

		case 1:
			if (year % 4 == 0)
			{
				numberOfDays = 29;
			}
			else
			{
				numberOfDays = 28;
			}
			myfile << "February \n";
			break;

		case 2:
			myfile << "March \n";
			numberOfDays = 31;
			break;

		case 3:
			myfile << "April \n";
			numberOfDays = 30;
			break;

		case 4:
			myfile << "May \n";
			numberOfDays = 31;
			break;

		case 5:
			myfile << "June \n";
			numberOfDays = 30;
			break;

		case 6:
			myfile << "July \n";
			numberOfDays = 31;
			break;

		case 7:
			myfile << "August \n";
			numberOfDays = 31;
			break;

		case 8:
			myfile << "September \n";
			numberOfDays = 30;
			break;

		case 9:
			myfile << "October \n";
			numberOfDays = 31;
			break;

		case 10:
			myfile << "November \n";
			numberOfDays = 30;
			break;

		case 11:
			myfile << "December \n";
			numberOfDays = 31;
			break;
		}

		

		myfile << "Sun\tMon\tTue\tWed\tThr\tFri\tSat\n";

		//this loop sets the position for the starting day
		for (int i = 0; i < beginingDay; i++)
		{
			myfile << " \t";
		}
		//This loop displays the days 
		for (int j = (1 + beginingDay); j <= (numberOfDays + beginingDay); j++)
		{
			myfile << (j - beginingDay) << "\t";

			if (j % 7 == 0) //ends the line at the end of each week
			{
				myfile << endl;
			}

		}
		
		beginingDay = (beginingDay + numberOfDays) % 7;
		myfile << endl;
		myfile << endl;
		counter++;
	}

	myfile << endl;

	myfile.close();
	system("PAUSE");
	return 0;
}
