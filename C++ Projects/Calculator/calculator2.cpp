#include <iostream>
using namespace std;

int main()
{
    float a,b,result;
    char operation;

    cout << "Enter 1st Number:" << endl;
    cin >> a;
    cout << "Enter 2nd Number:" << endl;
    cin >> b;
    cout << "Enter Operation(+,-,/,*):" << endl;
    cin >> operation;

    
    
    if (operation == '+')
    {
        result = a + b;
    }
    else if (operation == '-')
    {
        result = a - b;
    }
    else if (operation == '/')
    {
        result = a / b;
    }
    else if (operation == '*')
    {
        result = a * b;
    }
    else
    {
        cout << "Invalid input " <<endl;
    }


    cout << "Result is:" << result << endl;
    return 0;

    
}