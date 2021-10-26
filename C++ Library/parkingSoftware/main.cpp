#include <iostream>
using namespace std;

class GuardAndManager{
protected:
      int ManagerPerDayPay=1000;
      int FloorAttendPerDayPay=500;
      int GuardPerDayPay=300;

public:
    int Salaries();

};


class Parking{
protected:
      int BparkingSlot=30;
      int GparkingSlot=40;
      int TparkingSlot=150;
      GuardAndManager obj;  //composition

public:
       int VanPlusHiceIn(int VanIn);
       int VanPlusHiceOut(int VanOut);
       int CarIn(int c1);
       int CarOut(int c2);
       int MotoBikesBiIn(int m1);
       int MotoBikesBiOut(int m2);
       int salary(){
       int sal=obj.Salaries();
          return sal; };

};


int main()
{ Parking Basement, GroundFloor, TopFloor, sal;

int totalVanParked=0,VanCharges;
int totalCarParked=0,CarCharges;
int totalMotoParked=0,MotoCharges;
int TotalAmount, SalariesAmount;
float tax;

while(true){
cout<<"Press 1 when a Van or Hi-aces in: "<<endl;
cout<<"Press 2 when a Van or Hi-aces out: "<<endl;
cout<<"Press 3 to check number of Van or Hi-aces parked in Basement:"<<endl;
cout<<"Press 4 when a car comes for parking: "<<endl;
cout<<"Press 5 when a car out from parking: "<<endl;
cout<<"Press 6 to check number of car parked in ground floor: "<<endl;
cout<<"Press 7 when a motor-bike or bicycle comes for parking: "<<endl;
cout<<"Press 8 when a motor-bike or bicycle out from parking: "<<endl;
cout<<"Press 9 to check number of motor-bikes or bicycle parked in Top floor: "<<endl;
cout<<"press 0 to GENERATE REPORT "<<endl;
cout<<endl;
cout<<endl;

int input;
cin>>input;
if(input==1){
    totalVanParked=Basement.VanPlusHiceIn(totalVanParked);
    VanCharges=50*totalVanParked;
    cout<<"van charges collected till now "<<VanCharges<<endl;
    }

else if(input==2){
        totalVanParked=Basement.VanPlusHiceOut(totalVanParked);

}
else if (input==3){
        cout<<"the number of van or hi-aces parked = "<<totalVanParked<<endl;
}
else if(input==4){
        totalCarParked=GroundFloor.CarIn(totalCarParked);
        CarCharges=totalCarParked*30;
        cout<<"car charges collected till now "<<CarCharges<<endl;
}
else if(input==5){
        totalCarParked=GroundFloor.CarOut(totalCarParked);
}
else if (input==6){
        cout<<"the number of car parked = "<<totalCarParked<<endl;
}
else if(input==7){
        totalMotoParked=TopFloor.MotoBikesBiIn(totalMotoParked);
        MotoCharges=totalMotoParked*20;
        cout<<"moto and bikes charges collected till now "<<MotoCharges<<endl;;
}
else if(input==8){
        totalMotoParked=TopFloor.MotoBikesBiOut(totalMotoParked);
}
else if (input==9){
        cout<<"the number of Moto-bikes and bicycle parked in Top Floor = "<<totalMotoParked<<endl;
}
else if(input==0){
        cout<<endl<<endl;
        cout<<"REPORT AT THE END OF THE DAY"<<endl;
        TotalAmount=VanCharges+CarCharges+MotoCharges;
        cout<<endl;
        cout<<"total amount = "<<TotalAmount<<endl;
        tax=0.05;   //5 divides by 100
        tax=tax*TotalAmount;
        TotalAmount=TotalAmount-tax;

        SalariesAmount=sal.salary();

        cout<<" 5% tax of the total amount paid to the Govt = "<<tax<<endl;
        cout<<" The Amount after paying 5% tax to govt is = "<<TotalAmount<<endl;
        cout<<"The Amount after paying Salaries of employees including Manager = "<<TotalAmount-SalariesAmount<<endl;
                break;
}
}
    return 0;
}



//IN AND OUT fUNCTIONS FOR VAN OR HI-ACES IN THE BASEMENT

int Parking::VanPlusHiceIn(int Number){

        if(Number<=BparkingSlot){
        Number++;}
        else{ cout<<"Nomore space for van "<<endl;
        }
        cout<<endl;
return Number;

}

int Parking :: VanPlusHiceOut(int n){
        n--;

return n;
}

//IN AND OUT fUNCTIONS FOR CARS IN THE GROUND FLOOR
int Parking :: CarIn(int car1){

        if(car1<=GparkingSlot){
        car1++;}
        else{cout<<"Nomore space for cars "<<endl;
        }

return car1;

}

int Parking :: CarOut(int car){
       car--;

return car;
}

//IN AND OUT fUNCTIONS FOR MOTOR-BIKES IN THE TOP FLOOR
int Parking :: MotoBikesBiIn(int bike1){

        if(bike1<=TparkingSlot){
        bike1++;}
        else{cout<<"Nomore Space For bikes "<<endl;
        }

return bike1;
        }


int Parking :: MotoBikesBiOut(int bike){
        bike--;

return bike;
}

//FUNCTION FOR SALARIES
int GuardAndManager ::Salaries(){
       int Totalsal=ManagerPerDayPay+(GuardPerDayPay*2)+(FloorAttendPerDayPay*3);
return Totalsal;
}
