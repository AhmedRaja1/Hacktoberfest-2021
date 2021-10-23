#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int master(int a, int b, int (*p)(int, int))
{
	int sum;
	sum = (*p)(a, b);
	return sum;
}
main()
{
	int x,y;
	cout<<"Enter two number : "<<endl;
	cin>>x>>y;
	char op;
	cout<<"Enter operator: ";
	cin >> op;
	switch (op)
	{
	case '+':
		cout <<"Result is : "<<master(x,y,add) ;
		break;
	case '-':
		cout<<"Result is : "<<master(x,y, sub);
		break;
	case '*':
		cout<<"Result is : "<<master(x,y, mul);
		break;

	case '/':
	    cout<<"Result is : "<<master(x,y, div);
		break;
		default:
		cout<<"Wrong operator entered";
	}
}

