#include <iostream>
using namespace std;

void swapNums(int &x, int &y) 
{
  
  int z = x;
  x = y;
  y = z;

  x=x+4;
  cout<<"firt number modified value:"<<x<<endl;

cout<<"address of firstNum: "<<&x<<endl;
cout<<"address of secondNum: "<<&y<<endl;

}

int main() {
  
  int firstNum = 10;
  int secondNum = 20;
  cout << "Before swap: " << "\n";
  cout << firstNum << secondNum<< "\n";
 
 swapNums(firstNum, secondNum);

  cout<<"address of firstNum: "<<&firstNum<<endl;
  cout<<"address of secondNum: "<<&secondNum<<endl;

    cout<<"firt number modified value:"<<firstNum<<endl;

  
//cout<<"address of firstNum: "<<&firstNum<<endl;
//cout<<"address of secondNum: "<<&secondNum<<endl;

  // cout << "After swap: " << "\n";
  // cout << firstNum << secondNum << "\n";

  return 0;
}