#include <iostream>

using namespace std;

void grade();
float grade(int marks);
char grade(float percentage);
void grade()
{
	int marks1;
    cout<<"Enter marks Out of 500: ";
    cin>>marks1;
    cout<<"Percentage="<<grade(marks1)<<endl;
    cout<<"Grade="<<grade(grade(marks1));
    
}
float grade(int marks)
{
    float percentage2;
    percentage2=(marks*100)/500;
    return percentage2;

}
char grade(float percentage)
{
    char grade1;
    if(percentage<=100 && percentage>=90)
    {
        return 'A';
    }
    else if(percentage<90 && percentage>=80)
    {
    	return 'B';
    }
    else if(percentage<80 && percentage>=70)
    {
        return 'C';
    }
    else if(percentage<70 && percentage>=60)
    {
        return 'D';
    }
    else if(percentage<60 && percentage>=50)
    {
        return 'E';
    }
    else 
    	return 'F';
}

main()
{
    grade();

}
