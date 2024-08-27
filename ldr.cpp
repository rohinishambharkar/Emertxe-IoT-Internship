#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   pinMode(LDR_SENSOR, INPUT);
   
}
void brightness_control(void)
{
  unsigned int adcVal;
  
  // to read values from the LDR sensor
  adcVal = analogRead(LDR_SENSOR);

  // convert it into 0 - 255 and reverse it
  adcVal = 255 - (adcVal / 4);

  // map(0, 1023, 255, 0)  -> it is a prebuild function to scale down and reverse the values we get from LDR sensor.

  // Controlling the brightness of the Garden Lights
  analogWrite(GARDEN_LIGHT, adcVal);

  delay(100);   

}
