/*****************************************************************

programming algorithm:This program carries out the mathematical problems:
addition, subtraction, division, multiplication and power
-the user inputs the number and symbol when the scan_data function is called
-does the operations required by the user by calling do_next_op function and scans the input again fron the error while, 'q' and '0' is not entered
note: -the main finction gives the user another chance if division by zero is entered
-the function scan_data tells the user the error when division by zero is entered
********************************************************************/

//directing the computer to the libraries needed for the program
#include <iostream>  //defines the input and output
#include<iomanip>   //used to modify the output in the screen
#include<cmath>   //defines the mathematical problem

//declararing the prototypes needed to make the program easier
float scan_data(char&, float&); //reads the inputs from the user
float do_next_op(char, float, float&);// do the necessary operation choosed by the user

using namespace std;

//global variables
char symbol1;  //stores the symbol inputed by ht user
float final_sum=0;  //used to retain the number gotten from each mathematical solution
float number1;  //stores the number inputed by the user
float answer;   //stores the overall answer after the user is done with the program
 
int main()
{
  cout<<fixed<<showpoint<<setprecision(1);  //outputs the number in the form required for the program
  scan_data(symbol1, number1);    //function call that gets the input from the user
  //used a do_while loop due an assumption that the program runs at least once
  do
    {
      final_sum=do_next_op(symbol1, number1, answer);  //function call that do the operation wanted by the user.
      cout<<"result so far is "<<final_sum<<endl;  //tell the user the answer gotten so far in the program
      scan_data(symbol1, number1);  //scans the user input again to know the next option
      while(symbol1=='/' && number1== 0.0)  //a loop to give another chance if a division by zero is entered
	{
	  scan_data(symbol1, number1);  //function call
	}
     
    }while(symbol1 != 'q' && number1 !=0); //condition to continue the another problem
    cout<<"final result is "<<answer<<endl;  //tells the user the overall answer
  return 0;
}
//**************************************************************************

//definition of the function that gets the user inputs
float scan_data(char& symbol, float& number1)  //the function name and parameters
{
  cin>>symbol>>number1;  //reads the user inputs
  if(symbol=='/' && number1==0.0) // an if expression if division by 0 is entered
    {
      cout<<"Error: division by zero"<<endl; //tells the user an error information
      cout<<"result so far is "<<final_sum<<endl;
    }
  return symbol,number1;
}

//definition of the function that solves the mathimatical problem
float do_next_op(char symbol, float number, float& answer)  //function name and parameters
{
  if(symbol=='+')  //an expression that carries out the addition problem
    {
      answer=final_sum+number;
      return answer; // returns the answer to the main function
    }
  else if(symbol=='-')  //an expression that carries out the subtraction problem
    {
      answer=final_sum-number;
      return answer;
    }
  else if(symbol=='*')  //an expression that do the multiplication problem
    {
      answer=final_sum*number;
      return answer;
    }
  else if(symbol=='/')  //an expression that carries out the division and returns answer to the main function
    {
      answer=final_sum/number;
      return answer;
    }
  else if(symbol=='^')  //an expression that carries out the power problem and returns the answer to the main function
    {
      answer=pow(final_sum, number);
      return answer;
    }
  else
    {
      cout<<"Error: invalid operator"<<endl; //prints out if the symbol entered is not required by the program
    }
  return answer;
}
