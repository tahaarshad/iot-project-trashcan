// Template ID, Device Name, and AuthToken copied from Blynk.cloud device info tab
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial


//Important libraries for ESP8266 and Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Trigger and Echo pins for Ultrasonic Sesnor. 12 is D6 and 14 and D5. Defining them as variable for easy understanding
#define trig 12 
#define echo 14

//Entering Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";
int depth =18; //Depth of trash can is 18cm

BlynkTimer timer;


//Function for monitoring garbage and sending notification 
void garbagelevel()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  //Calculating percentage
  long level= depth-cm;
  if (level<0)
  level=0;
  level = map(level,0,depth-3,0,100);
  Blynk.virtualWrite(V0, level);
//Notifcation
  if (level>85) {
    Blynk.logEvent("garbage_full","garbage level is above 85%");
    }
}

//Library for servo motor
#include <Servo.h>
//defining servo as sl 
Servo s1; 

//IR sensor input pin is D2
int inputPin = 4;  
int val = 0; 

void setup() {
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, garbagelevel);
  
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  s1.attach(0); //0 is D3, which is input pin of Servo motor
}

void loop() {
  Blynk.run();
  timer.run();
//Motor trigger
  val = digitalRead(inputPin);
  if (val == LOW)
  { 
    Serial.println("Motion detected!");
    s1.write(180);  
    delay(3000);
    s1.write(0);  
   }

}
