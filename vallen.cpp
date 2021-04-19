#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main ()
{
    srand(time(NULL));
   
    ifstream input;
    string str;
    string strsurname;
    
    input.open("students.txt");
    
    while (!input)
    {
        cout << "couldnt open input file successfully"<< endl;
        return 1;
    }
    
    getline(input, str);
    while(input)
    {
        strsurname = str.substr(str.find(" ")+1, str.length());
        str.at(0) = tolower(str.at(0));
        strsurname.at(0) = tolower(strsurname.at(0));
        
        if (strsurname.length() >= 10)
        {
            cout << strsurname.substr(0, 10) << "@uregina.ca" << endl;
        }
          else if (strsurname.length() == 9)
        {
            cout << strsurname << rand() % 10 << "@uregina.ca" << endl;
        }
        else if (strsurname.length() == 8)
        {
            cout << strsurname << 10 + rand() % 90 << "@uregina.ca" << endl;
        }
        else if (strsurname.length() == 7)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "@uregina.ca" << endl;
        }
        else if (strsurname.length() == 6)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "x@uregina.ca" << endl;
        }
        else if (strsurname.length() == 5)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "xx@uregina.ca" << endl;
        }
        else if (strsurname.length() == 4)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "xxx@uregina.ca" << endl;
        }
        else if (strsurname.length() == 3)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "xxxx@uregina.ca" << endl;
        }
        else if (strsurname.length() == 2)
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "xxxxx@uregina.ca" << endl;
        }
        else
        {
            cout << strsurname << 10 + rand() % 90 << str.at(0) << "xxxxxx@uregina.ca" << endl;
        }
        
        getline(input, str);
        
    }
    
        
    
    return 0;
}










