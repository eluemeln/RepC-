ile nmae: Calendar.h(header file)

file algorithm:

-define a class type called date

-decleared my data private

-decleared needed function for the program public

Note: the 'toString' function returns only the date and month in string version

- the function 'getyear' is used to print the year to the user

****************************************************/

#ifndef Calendar_h  //used to avoid compiling the .h file twice at once 

#define Calendar_h //defines the file again if correction is made in the file

#include<iostream>  //used for defining inputs and outputs throughout the program

using namespace std;



class Date  //declearing the datatype date

{

  //declaring the data private not to be accessed directly by the driver

 private:

  int month, day, year;  //stores the day, month, and year entered

 public:

  //constructors

  Date();  //initializes the data variables in the program to any value given in the implemtation file

  Date(int,int,int);  //used to overload the value given by the default constructor



  //functions needed in the program

  void nextDate();  //used to determine the next date in the program

  string toString();  //converts the integer date to string version in the program 



  //getter

  int getYear()const; //used to print out  the date in the program

 

};


#endif //class definition ends







file nmae: Calendar.cpp(implimentation file)

file algorithm:

-all the function is being defined here

-all the functions here will belong to the class Date

*************************************************/

#include "Calendar.h"  //including the user defined file which is the .h file



Date::Date()  //default constructor definition

{

  day=01;  //initializes the day to 1 by default

  month=01; //initializes the month to 1 by default

  year=1900; //initializes the year to 1900 by default

}



Date::Date(int m,int d,int y)  //constructor definition which can be used in driver

{

  month=m;  //assigns the value stored in m when used in the driver to the private data month

  day=d; //assigns the value stored in d when used in the driver to the private data day

   year=y; //assigns the value stored in y when used in the driver to the private data year

}



string Date::toString()  //function definiton with no parameters

{

  //local variables  

  string stringDay;  //stores the corresponding string for day entered

  string stringMonth; //stores the corresponding string for month entered

  string stringDate; //used to store the corresponding string for month and day when combined

  //a string array used to store the days of the month. note: each day is has index of day-1

  string dayList[31]={" 1st"," 2nd"," 3rd"," 4th"," 5th"," 6th"," 7th"," 8th"," 9th"," 10th"," 11th"," 12th"," 13th"," 14th"," 15th"," 16th"," 17th"," 18th"," 19th"," 20th"," 21st"," 22nd"," 23rd"," 24th"," 25th"," 26th"," 27th"," 28th"," 29th"," 30th"," 31th"};

  //a string array used to store the months of the year. note: each day is has index of month-1

  string monthList[12]={"January","February" ,"March","April","May","June","July","August","September","October","November","December"};



  for(int j=0;j<12;j++)//a loop used to access all the index to check the corresponding index of month-1

    {

      if(month-1==j)

{ //assertion: the index is found

  stringMonth=monthList[j]; // assigns the corresponding month string to the variable stingMonth

}

    }



 for(int i=0;i<31;i++)//a loop used to access all the index to check the corresponding index of day-1

   {

     if(day-1==i)

       { //assertion: the index is found

       stringDay=dayList[i]; // assigns the corresponding day string to the variable stingMonth

       }

   }

 stringDate=stringMonth+stringDay; //combines the month and day string and assigns it to to a string variable



 return stringDate;  //returns the string to main function

 

}

void Date::nextDate()  //function definition with no parameters

{ 

  if(day==31&&month==12) //an expression to check if its the its the last day of the year

    {

      day=1; //assigns 1 to the variable day

      month=1; //assigns one to the month

      year=year+1; //increases the year by one

    }

  else if(day==31) //an expression if its last day of the month

    {//assertion: its the last day of the month

    day=1; 

    month=month+1;//increases the month by one

    }

 else if(day==28&&month==2) //an expression to check the month of february if the nextday should be 1 0r 29 

   {

     if(year%4==0) //checks if its a leap year

       {//assertion: its a leap year

    day=1; //assigns 1 to the variable day

    month=month+1; //increases the month by one

      }

  else

    {//assertion: its not a leap year

      day=day+1;//increases the day by one

    }

   }

  else

    {//assertion its not the last day of the month

    day=day+1;//increases the day by one

    }

}





int Date::getYear() const //function definition

{

  return year;  //returns the year

}



file nmae: TestCalendar.cpp(Driver)

file algorithm:

-declare an instance of the class Date

-prompts the user to enter the date

-gets the date from the user

-apply the function toString on the object Date declared as an instance which convert the date to string

-prints the string returned to the screen

-apply the function nextDate on the object Date declared as an instance which produce the next date

-converts it to string again

-prints it out

Note:- a do while loop is used do to the program must run atleast once

-the getter is used to print the date

************************************************/

#include "Calendar.h"//including the user defined file which is the .h file



int main() //main function starts

{

  //local variables

  int m,y,d; //stores the  month, day and year enterd

  char dash1,dash2; //stores the dashes entered

  string stringDate,stringDate2; //stores t5he initial date and the next date

  char letter;  //stores the letter entered by the user to continue or not

 

do

  {//the user runs the program 

    cout<<endl; 

    cout<<"Enter a new date using the format mm-dd-yyyy: ";//prompts the user to enter the date

    cin>>m; //gets the month

    cin>>dash1;//gets the first dash

    cin>>d; //gets the day

    cin>>dash2; //gets the second dash

    cin>>y;  //gets the year

    while(d<1||d>31||m<1||m>12) //checks if a correct date is entered

      {//assertion: an incorrect date is entered

cout<<"Incorrect!"<<endl; //tells the user the date was not correct

cout<<"Enter a new date using the format mm-dd-yyyy: ";  //prompts the user to enter another date

  cin>>m; //gets the month

  cin>>dash1;//gets the first dash

  cin>>d;//gets the day

  cin>>dash2;//gets the second dash

  cin>>y; //gets the year

    } 

    Date date1(m,d,y); //calls the constructor to overload the default initialization donr by the default constructor

    stringDate=date1.toString(); //convetrs the date to string and assigns the returned string the the variable

    cout<<"The string version of the date is: "; //tells the user the string version of the date

    cout<<stringDate<<", "<<date1.getYear()<<endl; //prints out the string date

    date1.nextDate();  //gets the next date

    stringDate2=date1.toString();  //convetrs the date to string and assigns the returned string the the variable

  cout<<"The next Date in string version is: "; //tells the user the string version of the date

  cout<<stringDate2<<", "<<date1.getYear()<<endl;//prints out the next string date

  cout<<"Do you want to continue [Y/N]: "; //prompts the user if he or she wants to continue

  cin>>letter;  //gets the letter

  }while(letter=='Y'||letter=='y'); 

//assertion: the user quits the program

 cout<<"Good bye!"<<endl; //prints to the screen 



 return 0;

}//end main





COMPILER = CC

DRIVER =TestCalendar

FILE = Calendar

\$(DRIVER) : \$(FILE).o \$(DRIVER).o 		

	$(COMPILER) -o \$(DRIVER) \$(FILE).o \$(DRIVER).o

$(DRIVER).o : \$(DRIVER).cpp \$(FILE).cpp \$(FILE).h

	\$(COMPILER) -c \$(DRIVER).cpp -o \$(DRIVER).o

\$(FILE).o : \$(FILE).cpp \$(FILE).h

	\$(COMPILER) -c \$(FILE).cpp

clean:


	@ /bin/rm -f *.o



