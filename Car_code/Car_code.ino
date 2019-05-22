/*
   Project Thuc Tap Thiet Ke He Thong

   Sensor in A1, A2, A3, A4, A5
   2 is Tx connect to Rx of ESP8266
   3 is Tx connect to Tx of ESP8266
   L298 in 6, 7, 8, 9
   Power and GND for SDreader and ESP8266

*/

#define speeds 35
#define drift 100
#define timeDelay 20

#define driftLong 200
#define speedsLong 200
#define timeDelayLong 1200
#define timeDelayBack 0

#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); // RX | TX

byte SpMax = 120;     //From 100 to 225


void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);

  pinMode(6, OUTPUT);//Set chân in1 của dc A là output
  pinMode(7, OUTPUT);//Set chân in2 của dc A là output
  pinMode(8, OUTPUT);//Set chân in1 của dc B là output
  pinMode(9, OUTPUT);//Set chân in2 của dc B là output

  pinMode(15, INPUT);//Set chân cảm biến 1 là input
  pinMode(16, INPUT);//Set chân cảm biến 2 là input
  pinMode(17, INPUT);//Set chân cảm biến 3 là input
  pinMode(18, INPUT);//Set chân cảm biến 4 là input
  pinMode(19, INPUT);//Set chân cảm biến 5 là input
  mySerial.println('1');

}

void loop() {

  //Serial.println(readLine());

  //if (readLine() == 2) {
    Moveon(speeds, speeds);
  //}

  /*if (readLine() == 1) {
    Right(drift);
    delay(timeDelay);
  }

  if (readLine() == 3) {
    Left(drift);
    delay(timeDelay);
  }
  //  mySerial.println('2');

  if (readLine() == -5) {
    Moveon(speedsLong, speedsLong);
    delay(250);

    rotateRight(driftLong);
    delay(timeDelayLong);

  }

  if (readLine() == 5) {
    Moveon(speedsLong, speedsLong);
    delay(250);

    rotateLeft(driftLong);
    delay(timeDelayLong);


  }

  if (readLine() == -1) {
    Moveon(0, 0);
    //    mySerial.println('4');
  }*/

}

boolean IFSensor (byte PinNumb)
{
  return (!digitalRead (PinNumb)); //   line is 1
  //   No line is 0
}

int readLine() {
  int sens1 = IFSensor(15);
  int sens2 = IFSensor(16);
  int sens3 = IFSensor(17);
  int sens4 = IFSensor(18);
  int sens5 = IFSensor(19);

  if (((sens2 && sens3) && ( sens1 + sens4 + sens5 == 0)) || ((sens2) && ( sens1 + sens4 + sens5 == 0))) {
    return 1;
  }
  if (((sens3 && sens4) && ( sens1 + sens2 + sens5 == 0)) || ((sens4) && ( sens1 + sens2 + sens5 == 0))) {
    return 3;
  }
  if ( sens1 + sens2 + sens3 + sens4 + sens5 == 5) {
    return 0;
  }
  if ((sens1 + sens2 +  sens4 + sens5 == 0 ) && (sens3)) {
    return 2;
  }
  if ((sens1 + sens2 +  sens3 == 3 ) && (sens4 +  sens5 == 0 )) {
    return -5;
  }
  if ((sens3 + sens4 +  sens5 == 3 ) && (sens1 +  sens2 == 0 )) {
    return 5;
  }

  return -1;

}

void Moveon ( byte speedL, byte speedR)
{
  analogWrite(11, speedL);
  analogWrite(10, speedR);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void Left(byte speedR)
{
  analogWrite(11, 0);
  analogWrite(10, speedR);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void Right( byte speedL)
{
  analogWrite(11, speedL);
  analogWrite(10, 0) ;
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void Back (byte Speed)
{
  analogWrite(11, Speed);
  analogWrite(10, Speed);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void rotateLeft(byte speedR)
{
  analogWrite(11, speedR);
  analogWrite(10, speedR);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void rotateRight( byte speedL)
{
  analogWrite(11, speedL);
  analogWrite(10, speedL) ;
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
