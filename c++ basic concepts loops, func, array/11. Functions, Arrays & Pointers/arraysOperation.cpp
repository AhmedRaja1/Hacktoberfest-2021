#include<iostream>
#include <conio.h>
using namespace std;
const int array_size=15;
int length = 0;
void inilitiaze_array(int[]);
void print_array(int[]);
bool isFull();
bool isEmpty();
void insert(int[]);
void insertAt(int[]);
void remove(int[]);
void removeAt(int []);
void creatVacancy(int [], int );

int main()
{
    int a[array_size];
    inilitiaze_array(a);
    print_array(a);
    insert(a);
    print_array(a);
    remove(a);
    print_array(a);
    insertAt(a);
    print_array(a);
    removeAt(a);
    print_array(a);
    cout<<endl;
    system("PAUSE");
}
//To inialitize the array by 1/3 of total.
void inilitiaze_array(int temp[])
{
for(int i=0; i<array_size/3; i++)
{
insert(temp);
}
}
// To print the whole array
void print_array(int temp[])
{
cout<<"\n-------------------------List---------------------------\n";
for(int i=0; i<length; i++)
{
cout<<temp[i]<<", ";
}
cout<<"\n\n\t\t[List Length = "<<length<<" & List Total Size : "<<array_size<<"]";
cout<<"\n________________________________________________________\n\n";
}

//It checks either array is full or not
bool isFull()
{
    if(array_size==length)
    {
    return true;
    }
    return false;
    //return (array_size==length);
}

// To check either list is empty or not.
bool isEmpty()
{
    return (length==0);
}

//To insert at last of array
void insert(int test[])
{
    if(isFull()!= true)
    {
        cout<<"Enter any integer value:> ";
        //length++;
        cin>>test[length];
        length++;
    }
    else
    {
        cout<<"List is already full";
    }
}


// To ceate vacancy at intended index...
void creatVacancy(int test[], int at)
{
for(int i=length-1;i>=at;i--)
{
test[i+1] = test[i];
}
}
// To insert at intended location
void insertAt(int test[])
{
if(isFull()!= true)
{
int at,value;
cout<<"Enter Location for entry:> ";
cin>>at;
cout<<"Enter some integer value:> ";
cin>>value;
creatVacancy(test,at-1);
test[at-1]=value;
length++;
}
else
{
cout<<"List is already full";
}
}
// To remove from last of list
void remove(int test[])
{
if(!isEmpty())
{
test[--length]=-1;
cout<<"\n One Last Emlement is removed from the list...\n";
}
else
{
cout<<"List is empty. So, NO element to remove from the list...";
}
}
// To remove from intended location from list
void removeAt(int test[])
{
if(!isEmpty())
{
int at;
cout<<"Enter Location to remove element: ";
cin>>at;
for(int i=at;i<length;i++)
{
test[i-1] = test[i];
}
length--;
}
else
{
cout<<"List is empty";

}
}
