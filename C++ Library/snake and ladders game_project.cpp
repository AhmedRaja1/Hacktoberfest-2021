#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; 

//first let us declare a few neccessary functions

void board(int []);//initialize function to draw the board

int check_progress();//initialize function to check game progress

int roll_dice();//initialize function to roll dice
int roll;

//then we declare some variables

int samraroll; //holds the rolled value for the playersamra
int wahizaroll; //holds the rolled value for playerwahiza

int input; //variable to hold the users input, any number to roll dice and 0 to quit game, although entering a not a number value ends  the game as well...

int progress; //holds the value for the progress

int samra = 0;

int wahiza = 0;

//both players' initial starting point is 0

int squares[100]; // for the 100 squares, wahiza's right counts from 0


int main() //this is where it all goes down in c++
{
    srand( time(NULL) ); //for random numbers

    string samraalert = ""; //to alert samra for your triumphs and misfortunes
    string wahizaalert = ""; // to alert wahiza for triumphs and misfortunes

    cout << "Welcome to snakes and ladders, Enter any number to roll dice, press 0 to quit\n\n";
    cout << "SNAKES\tLADDERS\n99-63\t4-41\n32-6\t67-92\n\n";

    for ( int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
        {
            squares[i] = i;
        }

    do // every game is in some sort of loop
    {
        cout << "enter: ";
        cin >> input;

        roll = roll_dice();//playerSamra rolls dice

        if( (roll + samra) > 100)
        {
            samra = samra; //playerSamra has rolled a number that exceeds the end point player remains where she is
        }
        else
        {
            squares[samra] = samra;//overwrite the current position
            samra = samra + roll;//move playersamra to a new position
        }

        wahizaroll= roll_dice();//playerwahiza rolls dice

        if( (wahizaroll + wahiza) > 100)
        {
            wahiza = wahiza; //wahiza has rolled a number that exceeds the end point, player remains where she is
        }
        else
        {
            squares[wahiza] = wahiza;//overwrite the current position
            wahiza = wahiza + wahizaroll;//move wahiza to a new position
        }

        switch(samra) // it is snakes and ladders, numbers represent the snakes and ladders
        {
            case 99:
            samra = 63;
            samraalert = "OOPS... samra ran into a snake!";
            break;

            case 32:
            samra = 6;
            samraalert = "OOPS... samra ran into a snake!";
            break;
            

            case 4:
            samra = 41;
            samraalert = "YAY! samra climbed a ladder!!!";
            break;

            case 67:
            samra = 92;
            samraalert = "YAY! samra climbed a ladder!!!";
            break;

            default:
            samraalert = "";

        }

        switch(wahiza)
        {
            case 99:
            wahiza = 63;
            wahizaalert = "OOPS... wahiza ran into a snake!";
            break;

            case 32:
            wahiza = 6;
            wahizaalert = "OOPS... wahiza ran into a snake!";
            break;

           
            case 4:
            wahiza = 41;
            wahizaalert = "HAHA! wahiza climbed a ladder!!!";
            break;

            case 67:
            wahiza = 92;
            wahizaalert = "HAHA! wahiza climbed a ladder!!!";
            break;
            
            default:
            wahizaalert = "";
        }

        squares[samra] = 200; //playersamra's position shall be represented by the integer 200
        squares[wahiza] = 300; //playerwahiza's position shall be represented by the integer 300

        if ( input != 0)
        {
            cout<<"samra rolled "<<roll<<" wahiza rolled "<<wahizaroll<<endl;
            cout<<"samra's Position: "<<samra<<" wahiza's Position: "<<wahiza<<endl;
            cout <<samraalert<<endl;
            cout <<wahizaalert<<endl;

            board(squares);
            cout << "SNAKES\tLADDERS\n99-63\t4-41\n32-6\t67-92\n\n"; //so the player knows which is a snake and that which is ladder
        }

        progress = check_progress();

    }
    while ( progress == 0 && input != 0 );

    if ( squares[100] == 200)
    {
        cout << "||GAME OVER!samra Wins!||"<<endl;
    }
    else if ( squares[100] == 300)
    {
        cout << "||GAME OVER! wahiza Wins!"<<endl;
    }
    else
    {
        cout << "You Quit!";
    }

    cin.get();
    cin.ignore();
}

void board(int squares[])//define the board drawing mechanism!
{
    cout << "----------------------------------------------------------------------------"<<endl<<endl;
         cout << squares[100]<<"\t"<<squares[99]<<"\t"<<squares[98]<<"\t"<<squares[97]<<"\t"<<squares[96]<<"\t"
         <<squares[95]<<"\t"<<squares[94]<<"\t"<<squares[93]<<"\t"<<squares[92]<<"\t"<<squares[91]<<endl<<endl;

         cout << squares[81]<<"\t"<<squares[82]<<"\t"<<squares[83]<<"\t"<<squares[84]<<"\t"<<squares[85]<<"\t"
         <<squares[86]<<"\t"<<squares[87]<<"\t"<<squares[88]<<"\t"<<squares[89]<<"\t"<<squares[90]<<endl<<endl;

         cout << squares[80]<<"\t"<<squares[79]<<"\t"<<squares[78]<<"\t"<<squares[77]<<"\t"<<squares[76]<<"\t"
         <<squares[75]<<"\t"<<squares[74]<<"\t"<<squares[73]<<"\t"<<squares[72]<<"\t"<<squares[71]<<endl<<endl;

         cout << squares[61]<<"\t"<<squares[62]<<"\t"<<squares[63]<<"\t"<<squares[64]<<"\t"<<squares[65]<<"\t"
         <<squares[66]<<"\t"<<squares[67]<<"\t"<<squares[68]<<"\t"<<squares[69]<<"\t"<<squares[70]<<endl<<endl;

         cout << squares[60]<<"\t"<<squares[59]<<"\t"<<squares[58]<<"\t"<<squares[57]<<"\t"<<squares[56]<<"\t"
         <<squares[55]<<"\t"<<squares[54]<<"\t"<<squares[53]<<"\t"<<squares[52]<<"\t"<<squares[51]<<endl<<endl;

         cout << squares[41]<<"\t"<<squares[42]<<"\t"<<squares[43]<<"\t"<<squares[44]<<"\t"<<squares[45]<<"\t"
         <<squares[46]<<"\t"<<squares[47]<<"\t"<<squares[48]<<"\t"<<squares[49]<<"\t"<<squares[50]<<endl<<endl;

         cout << squares[40]<<"\t"<<squares[39]<<"\t"<<squares[38]<<"\t"<<squares[37]<<"\t"<<squares[36]<<"\t"
         <<squares[35]<<"\t"<<squares[34]<<"\t"<<squares[33]<<"\t"<<squares[32]<<"\t"<<squares[31]<<endl<<endl;

         cout << squares[21]<<"\t"<<squares[22]<<"\t"<<squares[23]<<"\t"<<squares[24]<<"\t"<<squares[25]<<"\t"
         <<squares[26]<<"\t"<<squares[27]<<"\t"<<squares[28]<<"\t"<<squares[29]<<"\t"<<squares[30]<<endl<<endl;

         cout << squares[20]<<"\t"<<squares[19]<<"\t"<<squares[18]<<"\t"<<squares[17]<<"\t"<<squares[16]<<"\t"
         <<squares[15]<<"\t"<<squares[14]<<"\t"<<squares[13]<<"\t"<<squares[12]<<"\t"<<squares[11]<<endl<<endl;

         cout << squares[1]<<"\t"<<squares[2]<<"\t"<<squares[3]<<"\t"<<squares[4]<<"\t"<<squares[5]<<"\t"
         <<squares[6]<<"\t"<<squares[7]<<"\t"<<squares[8]<<"\t"<<squares[9]<<"\t"<<squares[10]<<endl<<endl;
    cout << "----------------------------------------------------------------------------"<<endl;
}

int roll_dice()//define the dice rolling mechanism
{
    return rand() % (7-1) + 1;//can only roll 1 - 6
}

int check_progress()//define the progress checking mechanism
{
    if ( squares[100] == 200 || squares[100] == 300)
    {
        return 1;//game has ended... win! someone has won
    }
    else
    {
        return 0;//game is still on, no one has won
    }
}
