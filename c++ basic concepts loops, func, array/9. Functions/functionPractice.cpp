#include <iostream>
using namespace std;


//void myFunction();

void myFun(string country="UK" , int ccode)   // formal arguments
{
  cout<<"Country name: "<<country<<endl;
  cout<<"Country Code: "<<ccode<<endl;

}



int main() { 

  myFun("pakistan", 123);   //actual arg 
  myFun("Qatar",233);
  myFun("Afgahnistan");
  
}




// void myFunction()
// {
//   cout<<"welcome to C++";
// }