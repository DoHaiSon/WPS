/* 
 *  Project Thuc Tap Thiet Ke He Thong
 *  
 *  Tx connect to 3 of UNO
 *  Rx connect to 2 of UNO
 *  D5 - SCK of SDreader
 *  D6 - MISO of SDreader
 *  D7 - MOSI of SDreader
 *  D8 - CS of SDreader
 *  
 */
#include <Arduino.h>
#include <SD.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>
const int chipSelect = D8; //CS in D8

File myFile;

ESP8266WiFiMulti WiFiMulti;

const char* SSID = "HTGROUP";      //Change to wifi's name, what esp'll connect
const char* PASSWORD = "12345654321!";    //Password for this

const char* host = "savedatatttkht.tk";
const uint16_t port = 80;

#define WIFI1 "BMTTVT_FET"    //Change to wifi's name, what u wanna meansure
#define WIFI2 "Tenda_HTVT"          //Change to wifi's name, what u wanna meansure
#define WIFI3 "TP-LINK_5268_VPK"        //Change to wifi's name, what u wanna meansure

char amount = '3';    //We'll have to re-code something if u want change this

int RSSI1 = 0;
int RSSI2 = 0;
int RSSI3 = 0;

char a;

int position = 1;

void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  /*for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
    }*/

  
  
  // wait for WiFi connection
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(SSID, PASSWORD);
  delay(5000);
  while (WiFiMulti.run() != WL_CONNECTED) {
    WiFiMulti.addAP(SSID, PASSWORD);
    Serial.print(".");
    delay(5000);
    //WiFi.reconnect();
  }

  if (!SD.begin(chipSelect)) { // CS is D8
    Serial.println("Initialising failed!");
    return;
  }
  Serial.println("Initialisation completed");
}

void loop() {
  if (Serial.available())
  {
    a = Serial.read();
    if (a == '1')
    {
      sendFirst();
      position = 1 ;
    }
    if (a == '2')
      sendBreak();
    if (a == '3')
      SDread();
    if (a == '4')
      {
        sendEnd();
        return;
      }
  }
  scan();
  sendMessage();
}

void sendFirst() {

  String text = "RSSI of ";
  text += WIFI1;
  text += "\tRSSI of ";
  text += WIFI2;
  text += "\tRSSI of ";
  text += WIFI3;
  SDdelete();
  SDwrite(text);


  WiFiClient client;
  HTTPClient http;

  if (!client.connect(host, port)) {
    Serial.println("Unable to connect\n");
    return;
  }

  String data = "http://www.savedatatttkht.tk/data.php/?control=start&quantity=";
  data += amount;
  data += "&name1=";
  data += WIFI1;
  data += "&name2=";
  data += WIFI2;
  data += "&name3=";
  data += WIFI3;
  http.begin(client, data);
  http.GET();
  http.end();

}

void sendMessage() {

  String text = "";
  text += RSSI1;
  text += "\t";
  text += RSSI2;
  text += "\t";
  text += RSSI3;
  SDwrite(text);


  WiFiClient client;
  HTTPClient http;

  if (!client.connect(host, port)) {
    Serial.println("Unable to connect\n");
    return;
  }

  String data = "http://www.savedatatttkht.tk/data.php/?";
  data += "position=";
  data += position++;
  data += "&RSSI1=";
  data += RSSI1;
  data += "&RSSI2=";
  data += RSSI2;
  data += "&RSSI3=";
  data += RSSI3;
  http.begin(client, data);
  http.GET();
  http.end();

}

void sendBreak() {

  SDwrite("Turning.");


  WiFiClient client;
  HTTPClient http;

  if (!client.connect(host, port)) {
    Serial.println("Unable to connect\n");
    return;
  }

  String data = "http://www.savedatatttkht.tk/data.php/?";
  data += "control=Turning";
  http.begin(client, data);
  http.GET();
  http.end();

}

void sendEnd() {

  SDwrite("Done!!");


  WiFiClient client;
  HTTPClient http;

  if (!client.connect(host, port)) {
    Serial.println("Unable to connect\n");
    return;
  }

  String data = "http://www.savedatatttkht.tk/data.php/?";
  data += "control=end";
  http.begin(client, data);
  http.GET();
  http.end();

}

void scan() {


  int n = WiFi.scanNetworks();

  if (n == 0) {
    Serial.println("No Networks Found");
  }
  else
  {
    for (int i = 0; i < n; ++i) {
      if ( WiFi.SSID(i) == WIFI1) {
        RSSI1 = WiFi.RSSI(i);
      }
    }

    for (int i = 0; i < n; ++i) {
      if ( WiFi.SSID(i) == WIFI2) {
        RSSI2 = WiFi.RSSI(i);
      }
    }

    for (int i = 0; i < n; ++i) {
      if ( WiFi.SSID(i) == WIFI3) {
        RSSI3 = WiFi.RSSI(i);
      }
    }
  }
}

void SDwrite(String data) {
  myFile = SD.open("data.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("Writing to data.txt...");
    myFile.println(data);
    // close the file:
    myFile.flush();
    myFile.close();
    Serial.println("Done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening data.txt");
  }
}

void SDread() {
  myFile = SD.open("data.txt");
  if (myFile) {
    Serial.println("data.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening data.txt");
  }
}

void SDdelete() {
  myFile = SD.open("data.txt");
  if (myFile)
    SD.remove("data.txt");
  myFile = SD.open("data.txt", FILE_WRITE);
  myFile.close();
}
