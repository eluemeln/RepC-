#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool islength(int);
bool numLet(string, int);	//Function headers
bool chkupper(string, int);
bool chkdigits(string, int);	
string pwd;
int main()
{
	int length;	//Holds length balue of password
	bool k;		//True if password is all letters and numbers
	bool upper; //True if password has atleast two uppercase letters
	bool digits; //True if passsword has atleast two digits
	cout << "This program will read passwords and display if they are valid" << endl
		<< "**The password must be at least 8 characters long**" << endl
		<< "**Must consist of letters and digits**" << endl
		<< "**Must contain at least two uppercase letters and two digits**" << endl;
	cout << " please enter a valid password" << endl;
	cin >> pwd;	//Password that user enters
		 
		length = pwd.size();	//Passwords length
		bool minSize;
		minSize = islength(length);	//Calls function that checks if length of pw is greater than 8 and returns value to minsize
		k = numLet(pwd, length);	//Calls function that checks if password is only all number and letters
		upper = chkupper(pwd, length);	//Call function that checks uppercase criteria
		digits = chkdigits(pwd, length);	//Calls function that checks if password had atleast two digits

		if (minSize && k && upper && digits)
			cout << "The password " << pwd << " is valid" << endl;
		else
			cout << "The password " << pwd << " is invalid" << endl;

		return 0;

	}

	bool islength(int size) 
	{
		if (size >= 8)
			return true;
		else
			return false;
	}


	bool numLet(string pwd, int x)
	{
		for (int i = 0; i < x; i++)
		{
			if (!isalnum(pwd[i]))
				return false;
			break;
		}

		return true;
	}

	bool chkupper(string pwd, int l)
	{
		int count = 0;
		for (int i = 0; i < l; i++)
		{
			if (isupper(pwd[i]))
				count++;
		}
		if (count >= 2)
			return true;
		else
			return false;
	}

	bool chkdigits(string pwd, int o)
	{
		int count = 0;
		for (int i = 0; i < o; i++)
		{
			if (isdigit(pwd[i]))
				count++;
		}
		if (count >= 2)
			return true;
		else
			return false;
	}
