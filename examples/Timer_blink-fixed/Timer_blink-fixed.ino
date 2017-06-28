/*
 * Timer library - Blink example:
 * Every half a second the LED on the 13 pin of the arduino blink for half a second
 * After the first second and every 4 seconds it prints to the serial monitor that 1 second passed since the last reset
 * Every 3 seconds it resets the serial monitor's timer and print it to the serial montior
 * 
 * Library and code written by VincNL
 * GitHub: https://github.com/VincNL
 * Origanally written on 05/02/2017 - uploaded on 28/06/2017
 *
 */

#include <Timer.h>
#define led_Pin 13 //uses the arduino's built in LED on pin 13
#define blinkT 500 //defines the blinking delay to 500 miliseconds

Timer t1; 
Timer serialT;

boolean ledState = false;
boolean printState = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(led_Pin, OUTPUT);
  digitalWrite(led_Pin, LOW);
}

void loop() 
{
  if (ledState == 0 && t1.stopClock(blinkT)) {
     digitalWrite(led_Pin, HIGH);
     ledState = 1;
  }
  
  else if (ledState && t1.stopClock(blinkT)) {
    digitalWrite(led_Pin, LOW);
    ledState = 0;
  }

  if (printState == 0 && serialT.timerLap(1000)) {
    Serial.println("1 Second left since last reset");
    printState = 1;
  }
  
  if (printState && serialT.timerLap(1001)) 
    printState = 0;

  if (serialT.stopClock(3000))
    Serial.println("Serial timer restarted");
}
