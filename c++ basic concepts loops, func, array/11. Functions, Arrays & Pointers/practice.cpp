#include <iostream>
using namespace std;


int addition(int a , int b)    // formal arguments
{
    //int sum=a+b;

    int c=6;
    a=a+3;

    int sum =a+b;
    cout<<"Sum is : "<<sum;
}

int main() {

    int x=5;
    int y=6;

    addition(x, y);       // actual arguments        

    //cout<<"Result is: "<<sum;

    // here we will pass the adrres of the x to a

}
