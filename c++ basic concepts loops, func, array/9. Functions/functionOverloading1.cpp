#include <iostream>
using namespace std;

void sum(int x, int y)  // formal arguments
	{
	cout<<"sum of int is: "<<(x+y)<<endl;
	}
    void sum(double x, double y)  // formal arguments
	{
	cout<<"sum of double is: "<<(x+y)<<endl;
	}
    void sum(int x, double y)  // formal arguments
	{
	cout<<"sum of int & double is: "<<(x+y)<<endl;
	}
    void sum(double x, int y)  // formal arguments
	{
	cout<<"sum of double & int is: "<<(x+y)<<endl;
	}

int main() {
    sum(3,5);
    sum(3.3,5.6);     	// actual arguments
    sum(3,5.4);       	// actual arguments
    sum(3.6,5);  		// actual arguments

  return 0;
}