#include <iostream>
using namespace std;
int main() {
cout<<"Enter any number: ";
int number;
cin>>number;
bool even;   // bool variable declaration

even = (number%2==0);

if(even)
{	
cout<<"Even number";
}
else
{
cout<<"Odd Number";
}	
return 0;
}
