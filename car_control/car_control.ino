#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

#define ENA 14  // Enable/speed motors Right        GPIO14(D5)
#define ENB 12  // Enable/speed motors Left         GPIO12(D6)
#define IN_1 15 // L298N in1 motors Right           GPIO15(D8)
#define IN_2 13 // L298N in2 motors Right           GPIO13(D7)
#define IN_3 2  // L298N in3 motors Left            GPIO2(D4)
#define IN_4 0  // L298N in4 motors Left            GPIO0(D3)

const char *SSID = "JonesNguyen";     //Change to wifi's name, what esp'll connect
const char *PASSWORD = "12345678qw"; //Password for this

const char *host = "savedatatttkht.ml";
const uint16_t port = 80;

#define WIFI1 "BMTTVT_FET"       //Change to wifi's name, what u wanna meansure
#define WIFI2 "Tenda_HTVT"       //Change to wifi's name, what u wanna meansure
#define WIFI3 "TP-LINK_5268_VPK" //Change to wifi's name, what u wanna meansure
#define WIFI4 "ROBOT1"
#define WIFI5 "DSC"
#define WIFI6 "P208A"

int RSSI1 = -100;
int RSSI2 = -100;
int RSSI3 = -100;
int RSSI4 = -100;
int RSSI5 = -100;
int RSSI6 = -100;

String dest = "";
int lineofdest = 0, positionofdest = 0, lineofpos = 0, positionofpos = 0;
int arr[2], break1 = 16, break2 = 4;
int pos_t[] = {0, 0};
bool start = true;
int arr_data[6];
int arr_10[5][6];
int t = 0;
int dest_t[2]={0,0};
float med[6] = {0, 0,0,0,0,0};
void data_col()
{   

    for (int i = 0; i < 5; i++)
    {
        Serial.print("scan\t");
        scan();
        arr_10[i][0] = RSSI1;
        arr_10[i][1] = RSSI2;
        arr_10[i][2] = RSSI3;
        arr_10[i][3] = RSSI4;
        arr_10[i][4] = RSSI5;
        arr_10[i][5] = RSSI6;
    }
}

void scan()
{   

    int n = WiFi.scanNetworks();

    if (n == 0)
    {
        Serial.println("No Networks Found");
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI1)
            {
                RSSI1 = WiFi.RSSI(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI2)
            {
                RSSI2 = WiFi.RSSI(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI3)
            {
                RSSI3 = WiFi.RSSI(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI4)
            {
                RSSI4 = WiFi.RSSI(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI5)
            {
                RSSI5 = WiFi.RSSI(i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (WiFi.SSID(i) == WIFI6)
            {
                RSSI6 = WiFi.RSSI(i);
            }
        }
    }
}

void medium_arr(int a[5][6])
{
    //determin medium of intensity wifi
    //1 BMTTVT
    //2 HTVT
    //3 VPK
    //4 ROBOT1
    //5 DSC
    //6 P208A

    int arr[6] = {0, 0, 0, 0, 0, 0};
    

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i] = arr[i] + a[j][i];
        }
    }

    for (int i = 0; i < 6; i++)
    {
        med[i] = arr[i] / 5;
        
//        sendtest(med[i]);
    }
  Serial.println("");
//  sendtest(1.11);
    
}

float dist_arr(float a[], float b[], int k)
{
    // a, b must be same lengh

    float sum_square = 0;
    for (int i = 0; i < k; i++)
    {
        sum_square = sum_square + (a[i] - b[i]) * (a[i] - b[i]);
    }
    float distance;
    distance = sqrt(sum_square);
    return distance;
}

void position_detect(bool start)
{
    int k = 6;

    /* centers of line 1 */
    float center[60][6] = {{-84.35353535, -72.02040816, -85.62903226, -83.73913043, -94.17      , -97.37      },
       {-83.45833333, -71.0989011 , -82.22222222, -83.22857143, -87.61333333, -96.05319149},
       {-83.26470588, -70.24210526, -79.91304348, -83.22727273, -87.55      , -95.39583333},
       {-81.88235294, -68.35789474, -79.62222222, -84.23404255, -87.67901235, -93.61386139},
       {-81.29347826, -66.05617978, -78.21212121, -84.51960784, -88.1875    , -92.83838384},
       {-81.41237113, -65.53608247, -78.03      , -85.82474227, -88.85365854, -90.        },
       {-81.56435644, -63.87096774, -76.61052632, -86.84536082, -88.9       , -89.70967742},
       {-81.3030303 , -63.87234043, -72.80392157, -87.51960784, -88.9       , -88.19148936},
       {-79.84782609, -65.25806452, -68.79      , -87.48039216, -89.40506329, -87.38043478},
       {-76.07446809, -65.82978723, -67.91089109, -87.55339806,  -89.5       , -86.82105263},
       {-75.19565217, -66.03960396, -68.71717172, -87.875     , -89.45679012, -83.60526316},
       {-74.43564356, -70.77319588, -70.15625   , -88.18518519, -89.39285714, -75.91578947},
       {-71.68421053, -71.35051546, -71.12871287, -88.0952381 , -89.19753086, -78.28735632},
       {-69.1875    , -74.37777778, -70.79381443, -88.14018692, -89.18072289, -77.04705882},
       {-68.7311828 , -75.76190476, -70.51041667, -88.47222222, -89.13095238, -75.95294118},
       {-68.36792453, -77.40186916, -64.17894737, -88.46902655, -89.07954545, -78.90804598},
       {-68.94897959, -78.86725664, -58.50961538, -88.50434783, -89.2       , -81.13592233},
       {-67.02247191, -80.21649485, -58.48421053, -88.86792453, -89.3253012 , -78.70833333},
       {-65.86206897, -82.17977528, -61.41860465, -88.95145631, -89.35      , -85.36470588},
       {-64.94623656, -82.3       , -65.12903226, -88.99090909, -89.29069767, -88.04587156}};

    float dist;
    pos_t[0] = 0;
    pos_t[1] = 0;
    if (start == true)
    {
        dist = dist_arr(center[0], med, k);
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 20; i++)
            {

                if (dist_arr(center[i + j * 20], med, k) < dist)
                {
                    dist = dist_arr(center[i + j * 20], med, k);
                    pos_t[1] = i;
                    pos_t[0] = j;
                }
            }
        }
    }

       if(start == false){
         dist = dist_arr(center[pos_t[1]+pos_t[0]*20], med,k);
    
         for(int i = 0; i<20; i++){
             if(dist_arr(center[i+pos_t[0]*20], med, k) < dist){
                dist =  dist_arr(center[i+pos_t[0]*20], med, k);
                pos_t[1] = i;
             }
         }
       }
}


void sendtest(float fl)
{
    WiFiClient client;
    HTTPClient http;
    if (!client.connect(host, port))
    {
        Serial.println("Unable to connect\n");
        return;
    }
    String data = "http://www.savedatatttkht.ml/test.php/?test=";
    data += fl;
    http.begin(client, data);
    http.GET();
    http.end();
}

void sendposition()
{
    WiFiClient client;
    HTTPClient http;
    if (!client.connect(host, port))
    {
        Serial.println("Unable to connect\n");
        return;
    }
    String data = "http://www.savedatatttkht.ml/position.php/?position=";
    data += lineofpos;
    data += "-";
    data += positionofpos;
    http.begin(client, data);
    http.GET();
    http.end();
}
String destination()
{
    char server[] = "savedatatttkht.ml";
    char path[] = "/dest.txt";
    WiFiClient client;
    HTTPClient http;
    if (client.connect(server, port))
    {
        client.print("GET /dest.txt");
        client.println(" HTTP/1.1");
        client.println("Host: www.savedatatttkht.ml");
        client.println("User-Agent: Arduino");
        client.println("Accept: text/html");
        client.println("Connection: close");
        client.println();
    }
    int count = 0;
    while (client.connected())
    {
        while (client.available())
        {
            char ch = client.read();
            if (ch == '*')
            {
                count = 1;
                continue;
            }
            if (count == 1)
            {
                dest += ch;
                if (dest.length() >= 4)
                {
                    client.stop();
                    break;
                }
            }
        }
    }
}

void lineandpos(String dest)
{
    String strline = "", strposition = "";
    for (int i = 0; i < 1; i++)
        strline += dest[i];
    for (int i = 2; i < dest.length(); i++)
        strposition += dest[i];
    lineofdest = strline.toInt();
    positionofdest = strposition.toInt();
}

void mapg2(int *arr)
{
    if (lineofdest == 1)
    {
        if (lineofpos == 1)
        {
            arr[0] = 8;
            arr[1] = 0;
        }
        if (lineofpos == 2)
        {
            if (positionofdest < break1)
            {
                arr[0] = 4;
                arr[1] = 8;
            }
            else
            {
                arr[0] = 6;
                arr[1] = 8;
            }
        }
        if (lineofpos == 3)
        {
            if (positionofpos < break2)
                if (positionofdest < break1)
                {
                    arr[0] = 6;
                    arr[1] = 4;
                }
                else
                {
                    arr[0] = 6;
                    arr[1] = 6;
                }
            else if (positionofdest < break1)
            {
                arr[0] = 4;
                arr[1] = 4;
            }
            else
            {
                arr[0] = 4;
                arr[1] = 6;
            }
        }
    }
    if (lineofdest == 2)
    {
        if (lineofpos == 1)
        {
            if (positionofpos < break1)
            {
                arr[0] = 6;
                arr[1] = 8;
            }
            else
            {
                arr[0] = 4;
                arr[1] = 8;
            }
        }
        if (lineofpos == 2)
        {
            arr[0] = 8;
            arr[1] = 0;
        }
        if (lineofpos == 3)
        {
            if (positionofpos < break2)
            {
                arr[0] = 6;
                arr[1] = 8;
            }
            else
            {
                arr[0] = 4;
                arr[1] = 8;
            }
        }
    }
    if (lineofdest == 3)
    {
        if (lineofpos == 1)
        {
            if (positionofpos < break1)
                if (positionofdest < break2)
                {
                    arr[0] = 6;
                    arr[1] = 4;
                }
                else
                {
                    arr[0] = 6;
                    arr[1] = 6;
                }
            else if (positionofdest < break2)
            {
                arr[0] = 4;
                arr[1] = 4;
            }
            else
            {
                arr[0] = 4;
                arr[1] = 6;
            }
        }
        if (lineofpos == 2)
        {
            if (positionofdest < break2)
            {
                arr[0] = 4;
                arr[1] = 8;
            }
            else
            {
                arr[0] = 6;
                arr[1] = 8;
            }
        }
        if (lineofpos == 3)
        {
            arr[0] = 8;
            arr[1] = 0;
        }
    }
}

void Moveon(int speedL, int speedR)
{
    analogWrite(ENA, speedL);
    analogWrite(ENB, speedR);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    return;
}

void Right(int speedL, int speedR)
{
    analogWrite(ENA, speedL);
    analogWrite(ENB, speedR);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    delay(1200);
    return;
}

void Left(int speedL, int speedR)
{
    analogWrite(ENA, speedL);
    analogWrite(ENB, speedR);
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    delay(1200);
    return;
}

void stopRobot()
{

    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    analogWrite(ENA, 600);

    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    analogWrite(ENB, 600);
    return;
}


int detect_turn(int *pos_t,int arr){
    int func = 0;
    if((pos_t[0] ==0 && pos_t[1] == 15)||(pos_t[0] == 0 && pos_t[1] == 16)){
      if(arr == 4 || arr == 6){
        func =  10;
        pos_t[0] = 1;
        pos_t[1] = 0; 
        }
    }
//    if((pos_t[2] == 2 && pos_t[1] == 1)||(pos_t[0] == 2 && pos_t[1] == 3)){
//      if(arr == 4 || arr == 6){
//        func = 10;
//        pos_t[0] = 1;
//        pos_t[1] = 20;
//        }
//      }
//(pos_t[0] == 1 && pos_t[1] == 0)||

    if(pos_t[0] == 1 && pos_t[1] == 20){
      if(arr == 4 || arr == 6){
        func = 10;
        if(pos_t[1]<10){
          pos_t[0] = 0;
          pos_t[1] = 16; 
          }
        if(pos_t[1]>10){
          pos_t[0] = 2;
          pos_t[1] = 3; 
          }
          
        }
      }
    
  return func; 
  }
  
bool detect_stop(int pos[2], int dest[2]){
    bool func = false;
        if(pos[1] == dest[1]+1  || pos[1] == dest[1]){
          func = true;
          }
  return func;
    }

void setup()
{

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);

    Serial.begin(115200);
    
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

    memset(arr_10, 0, sizeof(arr_10));
    data_col();
    medium_arr(arr_10);

    position_detect(true);
   
    lineofpos = pos_t[0] + 1;
    positionofpos = pos_t[1];
    do {
      destination();
    delay(1000);
    lineandpos(dest);
    delay(500); } while(lineofdest == 0);
    sendposition();
    
    mapg2(arr);


    sendtest(arr[0]);
    sendtest(arr[1]);
    dest_t[0] = lineofdest - 1; 
    dest_t[1] = positionofdest; 

    Serial.println(dest[1]);
    
}


void loop()
{   
    
    Serial.print(pos_t[0]);
    Serial.print("\t");
    Serial.println(pos_t[1]);  
    Moveon(300 , 300); 
   

    data_col();
    medium_arr(arr_10);
    
    position_detect(false);


    if(detect_turn( pos_t, arr[t]) == 10){
      if(arr[t] == 4){
        Left(800, 800);
        }
      if(arr[t] == 6){
        Right(800,800);
        }
        t = 1;
      }
  
    if(detect_stop(pos_t, dest_t)){
      stopRobot();
      delay(10000);
      }
  
      pos_t[1] = pos_t[1];
      delay(1000);
    
    lineofpos = pos_t[0] + 1;
    positionofpos = pos_t[1];
    sendposition(); 
}
