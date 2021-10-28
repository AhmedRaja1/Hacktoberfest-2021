#include <iostream>
#include <math.h>
using namespace std;

void roots(){
	cout<<"in the Quardratic Eqation ax2+bx+c "<<endl;
	cout<<"Enter values of a,b and c, a should not be equal to zero "<<endl;
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	int d;
	d=((b*b)-4*(a*c));
	if(a!=0){
		int r1,r2;
		if(d>0)
		{
			r1 = (-b + sqrt(d)) / (2*a);
			r2 = (-b - sqrt(d)) / (2*a);
			cout<<"Two real roots. 1st root is: "<<r1<<" and 2nd root is :"<<r2<<endl;
		}
		else if(d==0)
		{
			r1 = -b / (2*a);
			cout<<"The roots are real and exact, which are: "<<r1<<endl;
		}
		else if(d<0)
		{
			r1=-b /(2 * a);
			r2=sqrt(-d) / (2*a);
			cout<<"Real and imaginary roots, Real root is: "<<r1<<" and imaginary root is: "<<r2;
		}
	}
	else{cout<<"a should not bee equal to zero.";
	}
}
main(){
	roots();
}
