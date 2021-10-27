#include <iostream> 
#include <conio.h> 
using namespace std; 

void repchar(char='*', int=45); 

int main()
{

repchar();

repchar('=');
repchar('+', 30);

}

void repchar(char ch, int n)
{
for(int j=0; j<n; j++)
cout << ch;
cout << endl;
}
