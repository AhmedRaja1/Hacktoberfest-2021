#include<iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter 3 digit number:";
    cin>>number;
    cout<<number%10;
    number=number/10;
    cout<<number%10;
    number=number/10;
    cout<<number;

}