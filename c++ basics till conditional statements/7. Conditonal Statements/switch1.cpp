#include <iostream>
using namespace std;
int main(){
   
   int i=2;

   switch(i) {
      
      case 1:
        cout<<"Case1 "<<endl;
        break;
      case 2:
        cout<<"Case2 "<<endl;
        break;
      case 3:
        cout<<"Case3 "<<endl;
        break;
      case 4:
        cout<<"Case4 "<<endl;
        break;

      default:
        cout<<"Default block executed..."<<endl;
    }
    return 0;
}
