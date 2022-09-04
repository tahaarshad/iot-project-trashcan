# IoT Project: Smart Trashcan
## Description
An IoT-Enabled Smart Trashcan that opens its lide when an object is near and further notifies the owner when the trashcan is full. The project was made using ESP8266 module, IR sensor, Ultrasonic sensor, Motor and Jumper wires.
## Background
A person is usually given the role of emptying trash bins when they are full in both open and closed environments. This is a traditional approach that is implemented everywhere for disposing of trash. The disadvantage to this approach is the person must come every time to check if the bins are full. Sometimes it is either empty and sometimes it is full and emitting bad odors. Furthermore, due to the pandemic, various hygiene concerns have also arisen demanding trash bins to have touch-less interaction capabilities. Thus, ineffective and inefficient management of waste can result in the over-accumulation of waste that can result in the emission of bad smell as well as act as a source of disease transmission. \
Implementing an IoT solution for this problem can bring many benefits to the environment. First, with the help of sensors and motors, a touchless solution can be implemented that opens the lid of the bin when the person is near. With the help of IoT, the janitor will be able to monitor the garbage level of trashcans in the college and empty it before it is full. This information can be accessed through an application and therefore, act as a proactive method of detecting the volume of trash and avoiding over-accumulation of garbage.
## Design
### Hardware
1x ESP8266\
1x Servo Motor\
1x Ultrasonic Sensor\
1x IR Sensor\
7x Female to Female Jumper Cables\
3x Male to Female Jumper Cables\
1x Micro USB to USB Cable
### Circuit Diagram
add image
### Flow Diagram
add image

## Software and Code
I used Blynk API for implementing IOT as it is easy to use and set up and because I am very well-versed in C++, I utilized the Arduino IDE.
Some of the fields have been left blank for you to enter yourself such as:
```
#define BLYNK_TEMPLATE_ID ""![circuit diagram](https://user-images.githubusercontent.com/53350641/188302836-5d338795-118f-4552-a9f8-44f6dbd9348e.png)

#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""
```
as well as:
```
> char ssid[] = "";
char pass[] = "";
```
