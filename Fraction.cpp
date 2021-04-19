**********************************************************************

program purpose: this program only does the basic calculation of arithemetic problem: addition,subtarction,multiplication,division
program algorithm:create a function called getFrac that gets each fraction
-create another fuction that gets the whole problem by calling the getfrac function
-create other functions that solve the problem according to the operator inputed
-prompts the user to enter fraction problem
-if denominator1 or denominator2 == 0,  tells the user an error message; else, it continue.
if the operator != '+', '-', '*', '/', the program prompts the user an error message
*************************************************************************/

#include<iostream>  //declaering directive that defines the input and the output to the computer

//declaring fuction prototypes needed by the program
void getFrac(int&, int&);  //reads in the fraction inputed by the user
void read_frac_problem(int&, int&, int&, int&, char&); //reads the whole fraction problem
int addFrac(int,int,int,int,int&,int&);  //does the addition problem
int multiplyFrac(int,int,int,int,int&,int&);  //does the multiplication problem
int subtractFrac(int,int,int,int,int&,int&);  //does the subtraction problem
int divideFrac(int,int,int,int,int&,int&);  //does the division problem

using namespace std;

//declaring global variables
char operatorr; //stores the symbol inputed by the user
int numerator1,numerator2,denominator1,denominator2; //stores the numbers inputed by the user for both numerator and denominator two fractions
int overall_num,overall_denom,final_numerator,final_denominator;  //stores the overall numbers returned by the functions after the wholw problem is solved
  
  int main()  //main function starts
{
  cout<<"Enter a common fraction problem: ";  //prompts the user to enter a fraction problem
  read_frac_problem(numerator1,denominator1,numerator2,denominator2,operatorr);  //fuction call to get the inputs from the user
  if(denominator1==0||denominator2==0)
    {
      cout<<"Cannot solve this problem!"<<endl;
    }
  else
{
    if(operatorr=='+')
      {
	addFrac(numerator1,denominator1,numerator2,denominator2,overall_num,overall_denom);  //function call to do the addition problem
	final_numerator=overall_num;  //assigns the final numerator returned to the variable
	final_denominator=overall_denom; //assigns the final denominator returned by the function to the variable
	cout<<"the result of the addition is "<<final_numerator<<"/"<<final_denominator<<endl;
      }
	else if(operatorr=='*')
	  {
	    multiplyFrac(numerator1,denominator1,numerator2,denominator2,overall_num,overall_denom);  //function call to do the multiplication problem
	final_numerator=overall_num;  //assigns the final numerator returned to the variable
	final_denominator=overall_denom; //assigns the final denominator returned by the function to the variable
	cout<<"the result of the multiplication is "<<final_numerator<<"/"<<final_denominator<<endl;
	  }
else if(operatorr=='-')
{
  subtractFrac(numerator1,denominator1,numerator2,denominator2,overall_num,overall_denom);  //function call to do the subtaction problem
	final_numerator=overall_num;  //assigns the final numerator returned to the variable
	final_denominator=overall_denom; //assigns the final denominator returned by the function to the variable
	cout<<"the result of the subtraction is "<<final_numerator<<"/"<<final_denominator<<endl;
 }
else if(operatorr=='/')
{
  divideFrac(numerator1,denominator1,numerator2,denominator2,overall_num,overall_denom);  //function call to do the division problem
	final_numerator=overall_num;  //assigns the final numerator returned to the variable
	final_denominator=overall_denom; //assigns the final denominator returned by the function to the variable
	cout<<"the result of the division is "<<final_numerator<<"/"<<final_denominator<<endl;
 }
 else
   {
     cout<<"Error: invalid operation!"<<endl;
   }
  }
  return 0;
}//main function ends
//****************************************************************************

//function definition thats reads the fraction from the user
void getFrac(int& numerator, int& denominator)  //function name and its prototypes
{
  char slash;  //a variable that stores the slashin pited by the user
  cin>>numerator>>slash>>denominator;  //values inputed by the user
}

//fuction definition that gets the whole equation from the user
void read_frac_problem(int& num1, int& denom1, int& num2, int& denom2, char& op)  //fiction name and its prototypes
{
  getFrac(num1,denom1);  //function call to get the fraction1
  cin>>op; //gets the operator inputed by the user
  getFrac(num2,denom2);  //function call to get fraction2
}

//function definition that sloves the subtarction problem
int subtractFrac(int num1, int denom1, int num2, int denom2, int& final_num, int& final_denom)  //function name with parameters
{
  int com_denom=denom1*denom2; // assigns the product of the two denominators to the variable
  int first_num=(com_denom/denom1)*num1;  //gets the first num of the fraction
  int second_num=(com_denom/denom2)*num2;  //gets the second num of the friaction
  final_num=first_num-second_num;  //subtacts the two number up and assigns it to a variable
  final_denom=com_denom;  //asigns the commom denominator as the final one
  return final_num,final_denom;  //returns the two values
}  //fuction end

//function definition that solves the addition problem
int addFrac(int num1, int denom1, int num2, int denom2, int& final_num, int& final_denom)  //function name with parameters
{
  int com_denom=denom1*denom2; // assigns the product of the two denominators to the variable
  int first_num=(com_denom/denom1)*num1;  //gets the first num of the fraction
  int second_num=(com_denom/denom2)*num2;  //gets the second num of the friaction
  final_num=first_num+second_num;  //sums the two number up and assigns it to a variable
  final_denom=com_denom;  //asigns the commom denominator as the final one
  return final_num,final_denom;  //returns the two values
}  //fuction end

//function definition that solves the division problem
int divideFrac (int num1, int denom1, int num2, int denom2, int& final_num, int& final_denom)  //function name with parameters
{
  final_num=num1*denom2;  //multiplys and assigns it to the variable
  final_denom=num2*denom1;
  return final_num,final_denom; //returns the values gotten
}




