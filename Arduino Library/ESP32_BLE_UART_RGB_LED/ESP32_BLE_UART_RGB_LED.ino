/*Created by Muhammad Hammad on 21st October, 2021,
   Email: muhammad.hammad1201@gmail.com
   Flame Control App tested with this example: https://github.com/hammad1201/FlameControlAndroid
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <ArduinoJson.h>

//Global Variables Definitions
int red = 13;
int green = 12;
int blue = 14;
StaticJsonDocument<200> doc;

// setting PWM properties
const int freq = 5000;
const int redLedChannel = 0;
const int greenLedChannel = 1;
const int blueLedChannel = 2;
const int resolution = 8;

//Function Declaration
void showColor(int , int, int);

//BLE Definitions
BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("Connected");
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("Disconnected");
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        deserializeJson(doc, rxValue);
        JsonObject obj = doc.as<JsonObject>();

        int redDutyCycle = doc["red"];
        int greenDutyCycle = doc["green"];
        int blueDutyCycle = doc["blue"];
        showColor(redDutyCycle, greenDutyCycle, blueDutyCycle);

        Serial.print("RED::");
        Serial.println(redDutyCycle);

        Serial.print("GREEN::");
        Serial.println(greenDutyCycle);

        Serial.print("BLUE::");
        Serial.println(blueDutyCycle);

        Serial.println("*********");
        Serial.print("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++) {
          Serial.print(rxValue[i]);
        }
        Serial.println();
        Serial.println();
        Serial.println("*********");

        rxValue = "";
      }
    }
};


void setup() {
  Serial.begin(115200);

  // BLE Steup
  BLEDevice::init("Flame Control");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pTxCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID_TX,
                        BLECharacteristic::PROPERTY_NOTIFY
                      );

  pTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE
                                          );

  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");

  //RGB LED Swtup
  ledcSetup(redLedChannel, freq, resolution);
  ledcSetup(greenLedChannel, freq, resolution);
  ledcSetup(blueLedChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(red, redLedChannel);
  ledcAttachPin(green, greenLedChannel);
  ledcAttachPin(blue, blueLedChannel);

  //Initially set the LED to Off
  ledcWrite(redLedChannel, 0);
  ledcWrite(greenLedChannel, 0);
  ledcWrite(blueLedChannel, 0);
}

void loop() {

  // Handle BLE Advertisement
  if (!deviceConnected && oldDeviceConnected) {
    delay(500); // give the bluetooth stack the chance to get things ready
    pServer->startAdvertising(); // restart advertising
    Serial.println("start advertising");
    oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
  }
}

void showColor(int redDutyCycle, int greenDutyCycle, int blueDutyCycle) {
  ledcWrite(redLedChannel, redDutyCycle);
  ledcWrite(greenLedChannel, greenDutyCycle);
  ledcWrite(blueLedChannel, blueDutyCycle);
}
