#include <iostream>
using namespace std;

int main() {

int array_size= 5;
int myNum[array_size]= {11,10,33,4,5};

int min =myNum[0];

for (int i = 0; i <array_size; i++)
{
    if (myNum[i] < min)
    {
        min=myNum[i];
    }
    
}
cout<<"Manimum number is: "<<min;

  return 0;
}
