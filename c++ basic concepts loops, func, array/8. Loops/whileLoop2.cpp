#include <iostream>
using namespace std;
 
int main () {
   // Local variable declaration:
	char c = 'n';
   // while loop execution

   while( c !='y' ) 
   {
	   cout << "in loop"<<endl;
      cout<<"Exit while loop(y/n)?";
	   cin>>c;
   }
   
   cout<<"=====OUTSIDE LOOP====="<<endl;
   return 0;
}
