/******************************************************
file name: Employee.h

file purpose: used to define the class "Employee"
and prototypes of function it needs
 ****************************************************/
#ifndef Employee_h  //used to avoid double definition of the class
#define Employee_h
#include<iostream>  //defines the input and output
#include<string>
using namespace std;

class employee
{
 private:
  string empName;  //stores the name of each employee
  string phoneNum;  //stores the phone number of each employee
 public:
  employee();  //default constructor
  void setName();  //set the name of the employee
  void setPhone();  //set the phone number of the employee
  void displayName();   //prints the name of the employee
  void displayPhone();  //prints the name of the employee 
 
  //overloaded operators
   friend ostream& operator<<(ostream&,const employee&);  
    bool operator >(const employee&)const;
};
#endif
