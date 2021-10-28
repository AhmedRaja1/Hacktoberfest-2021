#include<iostream>
//#include<string>
using namespace std;

int array_size;

void arrayIterationFunction(int test[])
{
    
    for (int i = 0; i <array_size; i++)
    {
        cout<<"Enter value at test["<<i<<"]=";
        cin>>test[i];
    }
    
    for (int i = 0; i <array_size; i++)
    {
        cout<<"myNum["<<i<<"]="<<test[i]<<endl;
    }
    
}

int main()
{       
    cout<<"Enter Array Size: ";

    cin>>array_size;
    
    int myNum[array_size];

    arrayIterationFunction(myNum);

}