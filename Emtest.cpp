file name:IndexList.h

program purpose: to get and arrage the name of employees
main algorithm:
  -get the number of employees to be entered
  -get their name and number
  -arrange the names in acending order by calling the selsort function 
 ****************************************************/
#include "IndexList.h"  //including user defined library
#include "IndexList.cpp"//including user defined library
#include "Employee.h"//including user defined library

using namespace std;

int main()  //main starts
{
  employee myEmployee;  //declaring a variable of class 
  const int maxSize=10;  //maximum number of employess the program can accept
  indexList<employee, maxSize>myEmployeeList;  //creating an indexList of employees
  //local datas
int numItems;
 int size;

 cout<<"List of type \"Employee\""<<endl;  //prompts the user
     cout << "Enter number of employees: ";
     cin >> numItems; //reads input from the user
	cout<<endl;
	size = 0;
if (numItems >= 0  &&  numItems <= maxSize)
  {//assertion: size entered is less than the maxsize for the program
	   while (size < numItems)
	   {
	     myEmployee.setName();  //gets the employee name
	     myEmployee.setPhone();  //gets the employee number
	     if(!myEmployeeList.append(myEmployee))
	       break;  //assertion:list is filled up
            size++;
	   }
  }
 myEmployeeList.selSort();  //function call to sort the employee's name
  cout<<endl;
  cout<<"Employee list sorted in ascending order: "<<endl;
  myEmployeeList.display(cout);  //prints the employees name

  return 0;
}
