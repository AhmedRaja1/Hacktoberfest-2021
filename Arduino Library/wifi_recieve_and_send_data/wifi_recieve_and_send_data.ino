#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

// Set these to your desired credentials.
const char *ssid = "hammad";
const char *password = "123456";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.print(c);
        client.write("Recieved "); //it runs again and again to the client
      }
    }
    // close the connection:
  }
}
