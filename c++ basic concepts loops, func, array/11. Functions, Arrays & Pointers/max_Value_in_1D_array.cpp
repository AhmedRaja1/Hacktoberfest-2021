#include <iostream>
using namespace std;

int main() {

int array_size= 5;
int myNum[array_size]= {11,10,33,4,5};

int max =myNum[0];



for (int i = 0; i <array_size; i++)
{
    if (myNum[i] > max)
    {
        max=myNum[i];
    }
    
}
cout<<"Maximum number is: "<<max;

  return 0;
}