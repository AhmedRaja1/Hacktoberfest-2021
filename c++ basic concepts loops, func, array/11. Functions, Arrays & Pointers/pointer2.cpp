#include <iostream>
using namespace std;

int main() {

int a, b;
int *x, *y;

a =  33;
b =  66;
x = &a;
y = &b;

cout<<"Memory address of variable a= "<<x<<endl;
cout<<"Memory address of variable b= "<<y<<endl;

//cout<<"Value in memory address x = "<<*x<<endl;
//cout<<"Value in memory address y = "<<*y<<endl;


  return 0;
}
