// I, Caleb Priede, 000803812 certify that this material is my original work.
// No other person's work has been used without due acknowledgement.
#include <Arduino.h>

float mapFloat(int x, float in_min, float in_max, float out_min, float out_max) {
  return ((float)x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;

  // read digitized value from D1 mini's A/D Converter
  iVal = analogRead(A0);

  // print value to the USD port
  float temp = mapFloat(iVal, 0.0f, 1023.0f, 0.0f, 50.0f);
  String textTemp = "";
  if(temp <= 10.0){
    textTemp = "Cold!";
  } else if(10.0 < temp && temp <= 15.0){
    textTemp = "Cool!";
  } else if(15.0 < temp && temp <= 25.0){
    textTemp = "Perfect!";
  } else if(25.0 < temp && temp <= 30.0){
    textTemp = "Warm!";
  } else if(30.0 < temp && temp < 35.0){
    textTemp = "Hot!";
  } else if(temp >= 35.0){
    textTemp = "Too Hot!";
  }
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + String(temp) + "deg. C which is " + textTemp);
  // wait 0.5 seconds
  delay(2000);
}