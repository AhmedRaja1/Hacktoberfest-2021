#include <iostream>
using namespace std;
int main(){
   int i=2;
   switch(i) {
      case 1:
        cout<<"Case1 "<<endl;
      case 2:
        cout<<"Case2 "<<endl;
      case 3:
        cout<<"Case3 "<<endl;
      case 4:
        cout<<"Case4 "<<endl;
      default:
        cout<<"Default block executed..."<<endl;
    }
    return 0;
}
