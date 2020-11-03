  
#include <avr/power.h>
#include <Wire.h>
#include "ClosedCube_HDC1080.h"

ClosedCube_HDC1080 hdc1080;
void setup()
{

  power_timer1_disable();// Timer 1
  power_timer2_disable();// Timer 2
  power_adc_disable(); // ADC converter
  power_spi_disable(); // SPI  
	hdc1080.begin(0x40);
  Serial.begin(115200); 
}

void loop()
{
  Serial.print("T=");
  Serial.print(hdc1080.readTemperature());
  Serial.print("C, RH=");
  Serial.print(hdc1080.readHumidity());
  Serial.println("%");
  delay(100);
}
