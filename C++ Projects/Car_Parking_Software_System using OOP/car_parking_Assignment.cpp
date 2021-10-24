#include <iostream>
#include <conio.h>
using namespace std;
class XYZ_Parking
{
    public:
    void Display()
        {
            cout << endl;
            cout<<"\t\t 1.Vans or Hi-aces " <<endl;
            cout<<"\t\t 2.Cars  " <<endl;
            cout<<"\t\t 3.Motor-bikes or Scooters or Bicycles  " <<endl;
            cout<<"\t\t 4.All details and parking status " <<endl;
            cout << endl;
        }
};
class Vehicle : public XYZ_Parking
{
    public:
        int a1,m1,m2,t1,t2,t3,m,s1,s2,s3,s4,s5,s6,sal1,sal2,sal3,sal4,sal5,sal6,total_salary,total,tax,tot_tax,tot_amount;
        int van,van_time,van_price,hiace,hiace_time,hiace_price;
        char van_member,hiace_member;
        int car,car_time,car_price;
        char car_member;
        int motorbike,scooter,bicycle,motorbike_time,motorbike_price,scooter_time,scooter_price,bicycle_time,bicycle_price,a2,b2;
        char motorbike_member,scooter_member,bicycle_member;
    
        
        void Basement()
        {
            cout << endl;
            cout << "Enter no of Vans: ";
            cin >> van;
            cout << "Enter no of Hi-aces: ";
            cin >> hiace;
            
            a1 = van+hiace;
            if (a1 > 30)
            {
                exit(1);
            }

            cout << "For van enter the no of times vehicle entered in parking slot today: ";
            cin >> van_time;

            cout << "For van enter the no of times vehicle entered in parking slot today: ";
            cin >> hiace_time;

            van_price = (van * 50 * van_time);    //For van
            hiace_price = (hiace * 50 * hiace_time);    //For hi-ace

        //For membership:

        cout << "Enter 'y' if van is in membership else enter 'n' : " ;
        cin >> van_member;
        m1 = (van_price) / 2;
        
        cout << "Enter 'y' if hi-ace is in membership else enter 'n' : " ;
        cin >> hiace_member;
        m2 = (hiace_price) / 2;
                cout << endl;

        }

        void Print_Details()
        {      
                        cout << endl;

                cout << "the number of vans are : " << van << endl;
                cout << "the number of hi_aces are : " << hiace << endl;

                // For van:
                if (van_member == 'y')
                    cout << "Van is in membership : " << m1 << endl;
                else
                    cout << "Van is not in membership : " << van_price << endl;

                // For hi-ace:
                if (hiace_member == 'y')
                    cout << "Hi-ace is in membership : " << m2 << endl;
                else
                    cout << "Hi-ace is not in membership : " << hiace_price << endl;  
                       cout << endl;

        }

        void Ground_Floor()
        {
                    cout << endl;

            cout << "Enter no of Cars: ";
            cin >> car;
            
            
            if (car > 40)
            {
                exit(1);
            }

            cout << "For car enter the no of times vehicle entered in parking slot today: ";
            cin >> car_time;


            car_price = (car * 30 * car_time);    //For car

        //For membership:

        cout << "Enter 'y' if car is in membership else enter 'n' : " ;
        cin >> car_member;

        m = (car_price) / 2;
                cout << endl;

        }

        void print_details()
        {      
                    cout << endl;

            
                cout << "the number of cars are : " << car << endl;

                // For van:
                if (car_member == 'y' || 'Y')
                {
                    cout << "Van is in membership : " << m << endl;
                }
                else
                {
                    cout << "Van is not in membership : " << car_price << endl;
                }
                        cout << endl;

        }

        void Top_Floor()
        {
                    cout << endl;

            cout << "Enter no of motorbikes: ";
            cin >> motorbike;
            cout << "Enter no of scooters: ";
            cin >> scooter;
            cout << "Enter no of bicycles: ";
            cin >> bicycle;

            a2 = motorbike+scooter;
            if (a2 > 100)
            {
                exit(1);
            }
            b2 = bicycle;
            if (b2 > 50)
            {
                exit(1);
            }

            cout << "For motorbike enter the no of times vehicle entered in parking slot today: ";
            cin >> motorbike_time;

            cout << "For scooter enter the no of times vehicle entered in parking slot today: ";
            cin >> scooter_time;

            cout << "For bicycle enter the no of times vehicle entered in parking slot today: ";
            cin >> bicycle_time;


            motorbike_price = (motorbike * 20 * motorbike_time);    //For motorbike
            scooter_price = (scooter * 20 * scooter_time);       //For scooter
            bicycle_price = (bicycle * 10 * bicycle_time);       //For bicycle

        //For membership:

        cout << "Enter 'y' if motorbike is in membership else enter 'n' : " ;
        cin >> motorbike_member;
        t1 = (motorbike_price) / 2;
        
        cout << "Enter 'y' if scooter is in membership else enter 'n' : " ;
        cin >> scooter_member;
        t2 = (scooter_price) / 2;

        cout << "Enter 'y' if bicycle is in membership else enter 'n' : " ;
        cin >> bicycle_member;
        t3 = (bicycle_price) / 2;

                    cout << endl;


        }

        void Print_details()
        {      
                    cout << endl;

                cout << "the number of motorbikes are : " << motorbike << endl;
                cout << "the number of scooters are : " << scooter << endl;
                cout << "the number of bicycles are : " << bicycle << endl;


                // For motorbike:
                if (motorbike_member == 'y')
                    cout << "motorbike is in membership : " << t1 << endl;
                else
                    cout << "motorbike is not in membership : " << motorbike_price << endl;

                // For scooter:
                if (scooter_member == 'y')
                    cout << "scooter is in membership : " << t2 << endl;
                else
                    cout << "scooter is not in membership : " << scooter_price << endl;

                // For bicycle:  
                if (bicycle_member == 'y')
                    cout << "bicycle is in membership : " << t3 << endl;
                else
                    cout << "bicycle is not in membership : " << bicycle_price  << endl; 
                            cout << endl;

        }

        void get_details()
        {
                    cout << endl;

            cout<<"Enter the no of days for the salary of general_manager : ";
            cin>>s1;
            cout<<"Enter the no of days for the salary of attendence 1 : ";
            cin>>s2;
            cout<<"Enter the no of days for the salary of attendence 2 : ";
            cin>>s3;
            cout<<"Enter the no of days for the salary of attendence 3 : ";
            cin>>s4;
            cout<<"Enter the no of days for the salary of guard 1 : ";
            cin>>s5;
            cout<<"Enter the no of days for the salary of guard 2 : ";
            cin>>s6;
               
        cout << endl;

            


        }

        void p_details()
        {
                    cout << endl;

            sal1 = (1000 * s1);
            cout<<"the salary of manager is : " << sal1 <<endl;
            sal2 = (500 * s2);
            cout<<"the salary of attendence is : " << sal2 <<endl;
            sal3 = (500 * s3);
            cout<<"the salary of attendence is : " << sal3 <<endl;
            sal4 = (500 * s4);
            cout<<"the salary of attendence is : " << sal4 <<endl;
            sal5 = (300 * s5);
            cout <<"the salary of guard is : " << sal5 <<endl;
            sal6 = (300 * s6);
            cout <<"the salary of guard is : " << sal6 <<endl;

            cout << endl;
            cout << "*** DETAILS OF XYZ PARKING ***" << endl;
            cout << endl;
            total_salary = (sal1+sal2+sal3+sal4+sal5+sal6);
            cout<<"Total salary of all members are : " << total_salary << endl;


            tot_amount = m1+m2+m+t1+t2+t3;
            cout << "Total amount= " << tot_amount << endl;

            total = (m1+m2+m+t1+t2+t3) - total_salary;
            cout << "Total amount after paying salary of all members= " << total << endl;

            //For tax:

            tax = total*0.05;
            tot_tax = total-tax;

            cout << "Total amount after paying tax= " << tot_tax << endl;

                    cout << endl;

            
            
        }

        

    




        
 
};

int main()
{
    int l=1;
    while (l=1)
    {
    int ch;
    Vehicle p1,p2;
    p1.Display();
    cout << "Choose Options: ";
    cin >> ch;
    if (ch == 1)
    {
        cout << "*** GO TO BASEMENT ***" << endl;
        p1.Basement();
        p1.Print_Details();
    }
    else if (ch == 2)
    {
        cout << "*** GO TO GROUND FLOOR ***" << endl;
        p1.Ground_Floor();
        p1.print_details();
    }
    
    else if (ch == 3)
    {
        cout << "*** GO TO TOP FLOOR ***" << endl;
        p1.Top_Floor();
        p1.Print_details();
    }

    
    else if (ch == 4)
    {
        p1.get_details();
        p1.p_details();
        break;
    }
    
    else
    {
        cout << "*** INVALID INPUT ***" << endl;
    }
    
    } 
  
    return 0;
}
