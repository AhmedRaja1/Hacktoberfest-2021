#include <iostream>
using namespace std;

int main() {

int xyz=6760;

//cout<<xyz;

//cout<<&xyz<<endl;

int *ref= &xyz;

cout<<"The address of normal Variable is: "<<ref<<endl;

void *pointerVariableAddress= &ref;

cout<<"The address of Reference Variable is: "<<pointerVariableAddress<<endl;



  return 0;
}




