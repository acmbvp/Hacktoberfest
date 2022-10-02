/*
 * Copyright (c) 2019 Oscar Casatmijana Vazquez 
 * 
 * This program is free software: 
 * you can redistribute it and/or modify it under the terms of the GNU General 
 * Public License as published by the Free Software Foundation, either version 3 
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. 
 * If not, see <https://www.gnu.org/licenses/>.
*/



// Simultaneous reading of multiple ultrasonic sensors

#include <Wire.h>

#define SLAVE_ADDRESS 0x30
#define TOTAL_SENSORS 6

#define TRIG  7
#define ECHO1 6
#define ECHO2 5
#define ECHO3 4

unsigned long maxloops;

long timesStart[TOTAL_SENSORS];
long timesStop[TOTAL_SENSORS];
uint8_t  distances[TOTAL_SENSORS+1];
uint8_t portB;
uint8_t portD;
char buff[10];

unsigned long start_time;

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(respondData); // register event
  Wire.onReceive(receiveRegister);
  Serial.begin(9600);
  
  DDRD = 0x80; //All bits as INPUT but TRIG (7)  
  DDRB = 0x00;
  portB = digitalPinToPort(9);
  portD = digitalPinToPort(7);
  maxloops = microsecondsToClockCycles(500);
}

void loop() {      
  memset (timesStart, 0, sizeof(timesStart));
  memset (timesStop, 0, sizeof(timesStop));
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  unsigned long numloops=0;
  uint8_t val, valPortB, valPortD;
  uint8_t sensorNum=0;

  start_time = millis();
  while (sensorNum < TOTAL_SENSORS && numloops < maxloops) {
    valPortD= *portInputRegister(portD);
    valPortB= *portInputRegister(portB);
    val = (valPortD & 0xfc)| (valPortB&0x3);
    uint8_t mask=0x40;
    for (int n=0;n<TOTAL_SENSORS; n++) {
      if ( (val & mask) == LOW ) {
        if ( timesStart[n] == 0) {          
          timesStop[n]=0;
        } else if (timesStop[n] == 0) { 
            timesStop[n]=micros()-timesStart[n];
            sensorNum++;          
          }        
      } else if (timesStart[n]==0) {  //HIGH        
          timesStart[n]=micros();
      }
      mask = (mask>>1);
    }
    numloops++;
  };

  //Serial.print (millis() - start_time);
  //Serial.print ("Distance : ");
  for (int n=0; n<TOTAL_SENSORS; n++) {
    distances[n] = (timesStop[n] * 0.034) / 2;
//    sprintf (buff, "%03d ", distances[n]);
//    Serial.print (buff);
  }  
//  Serial.println (" ");

  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void respondData() {
  Wire.write (distances,TOTAL_SENSORS);
}

void receiveRegister(int byteCount) {
}
