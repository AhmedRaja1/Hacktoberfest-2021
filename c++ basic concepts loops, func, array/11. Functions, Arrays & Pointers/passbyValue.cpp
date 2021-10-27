#include<iostream>
using namespace std;

void sum(int x, int y)
{

    x=x+3;
    int sum =x+y;
    cout<<"Result is: "<<sum;
}

int main()
{
    
    int a=5;
    int b=6;
    
    sum(a,b);
    
    
    return 0;

    
}