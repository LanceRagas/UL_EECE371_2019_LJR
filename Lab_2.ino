// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
int potRPin = 1;        //pin for the red potentiometer
int potGPin = 2;  //pin for the green potentiometer
int potBPin = 3;  //pin for the blue potentiometer
int valR =0;
int valG =0;
int valB =0;

void setup() {

  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);

}//end setuo()

void loop() {

  delay(100);

}//end loop()

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {

    Serial.println("requested");
    valR = 22;
    valG = 222;
    valB = 2222;
//    valR=map(valR, 0, 1024, 0, 255); 
//    valG=map(valG, 0, 1024, 0, 255);
//    valB=map(valB, 0, 1024, 0, 255);
    String red = String(valR);
    String green = String(valG);
    String blue = String(valB);
    String color = "" + red+","+blue+","+green;
    char colorArray[color.length()+1];
    color.toCharArray(colorArray, color.length()+1);
    Serial.println(color);
    Wire.write(colorArray);

}//end requestEvent()
