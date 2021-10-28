#include<iostream>
using namespace std;

int main()
{
bool job; char martialStatus; int age;

cout<<"Enter Martial Status:";
cin>>martialStatus;

cout<<"Enter age:";
cin>>age;

cout<<"Enter job Status:";
cin>>job;

if(martialStatus =='u')
{

    if(age <=25)
    {
        if(job == false)
        {
            cout<<"Eligible for Loan";

        }
            
    }      
}

else
{
    cout<<"Not eligible for Loan";
}



return 0;  

}