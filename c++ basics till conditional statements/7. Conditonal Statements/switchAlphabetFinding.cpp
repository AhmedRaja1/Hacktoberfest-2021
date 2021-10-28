#include <iostream>
using namespace std;
int main() {
cout<<"Enter alphabet: ";
char alphabet;
cin>>alphabet;
switch(alphabet)
{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
    case 'u':
	case 'A':
	case 'E':
	case 'I':
    case 'O':
	case 'U':
	cout<<"You entered vowel";
	break;
	default:
	cout<<"You entered consonant";
}   // switch body Closed
return 0;
}
