#include <iostream>
using namespace std;

int sum(int x, int y)  // formal arguments
	{
	 return(x+y);
    }

int main() {

    int result=sum(5,6);      //Actual Arguments
    cout<<"Result is: "<<result;
    //cout<<"Result is: "<<sum(5,6); 
    return 0;
}