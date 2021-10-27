#include<iostream>
using namespace std;

void arrayIterationFunction(int test[])
{
    for (int i = 0; i < 6 ; i++)
    {
        cout<<"myNum["<<i<<"]="<<test[i]<<endl;
    
    }
    
}

int main()
{
    
    int myNum[] = {1,3,4,5,6,7};
    
    arrayIterationFunction(myNum);


    //pass array to a function by reference 
    // and then let me know please



}