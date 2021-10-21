
#include "Arduino.h"
#define IRLINEFOLLOW_PIN_OUT	0
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;
void setup() 
{
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(, INPUT);
    menuOption = menu();
    
}
void loop() 
{
    
    
    if(menuOption == '1') {
    bool irLineFollowVar = digitalRead();
    Serial.print(F("LineFollow: ")); Serial.println(irLineFollowVar);

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) IR Line Track Follower Sensor"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing IR Line Track Follower Sensor"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
