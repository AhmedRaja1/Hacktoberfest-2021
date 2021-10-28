#include <iostream>
using namespace std;
 
int main () 
{
   // Local variable declaration:
	char c ;

   // do-while loop execution
      do
	  {
	   cout << "in loop"<<endl;
      cout<<"Exit while loop(y/n)?";
	   cin>>c;
   }
   while( c !='y' ); 

   cout<<"=====OUTSIDE LOOP====="<<endl;
   return 0;
}
