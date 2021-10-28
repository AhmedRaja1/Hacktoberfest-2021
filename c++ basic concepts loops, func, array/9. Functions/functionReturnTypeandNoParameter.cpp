#include <iostream>
using namespace std;

int sum()  // formal arguments
	{
    int x=50;
    int y=3;
	return(x+y);
    }

int main() {

    int result=sum();
    cout<<"Result is: "<<result;
    //cout<<"Result is: "<<sum(); 
    return 0;
}