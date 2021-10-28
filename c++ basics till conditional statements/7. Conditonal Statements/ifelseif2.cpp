#include<iostream>
using namespace std;
int main()
{
int number;
cout<<"Enter a number between 1 to 3:";
cin>> number;

if(number == 1)
{
cout<<"You pressed 1" <<endl;
}
else if(number ==2)
{
cout<<"You pressed 2" <<endl;
}
else if(number == 3)
{
cout<<"You pressed 3" <<endl;
}

else
{
cout<<"Invalid input";
}

}