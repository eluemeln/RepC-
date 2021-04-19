/******************************************************
file name: Employee.h

file purpose: used define the prototypes of the functions declared in Employee.h
 ****************************************************/

#include "Employee.h"  
#include<iostream>    //defines the input and output
employee::employee()
{
  empName="";  //initialisez the string to empty
  phoneNum="";   //initialisez the string to empty
}

void employee::setName()
{
  cout<<"Enter next name: ";   //prompts the user
  cin>>empName;   //reads input
}

void employee::setPhone()
{
  cout<<"Enter next phone number: "; //prompts the user
  cin>>phoneNum;    //reads input
}

void  employee::displayName()
{
  cout<<empName;     //prints name
}

void employee::displayPhone()
{
  cout<< phoneNum;  //prints phone number
}


bool employee::operator >(const employee&a)const
{
  return(empName>a.empName);
} 
ostream& operator<<(ostream& ous ,const employee& e)
{
  ous<<e.empName;
  return ous;  //returns the variable
}
