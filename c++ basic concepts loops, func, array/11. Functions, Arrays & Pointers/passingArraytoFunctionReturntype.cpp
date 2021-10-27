#include<iostream>
//#include<string>
using namespace std;

int* arrayIterationFunction(int array_size)
{
   
    int myNum[array_size];

    for (size_t i = 0; i <array_size; i++)
    {
        cout<<"Enter value at test["<<i<<"]=";
        cin>>myNum[i];
    }

    return myNum;
    
    
    
}

int main()
{

     int array_size;
    cout<<"Enter Array Size: ";
    cin>>array_size;

    int* p=arrayIterationFunction(array_size);

    //cout<<"myNum["<<2<<"]="<<p<<endl;

    cout<<p;


    for (int i = 0; i <array_size ; i++)
    {
        cout<<"myNum["<<i<<"]="<<p[i]<<endl;
    }

}