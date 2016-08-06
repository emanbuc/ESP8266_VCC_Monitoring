
/* ========= PRODUCT INFORMATION  =========== */
#define FW_REVISION 3
#define FW_NAME "Vcc monitoring native SDK"
/* -------------------- */


/*
 Author: Emanuele Buchicchio
 Created on 06 August 2016 
 https://github.com/emanbuc/ESP8266_VCC_Monitoring
 http://blog.emanuelebuchicchio.com

*/

// Expose Espressif SDK functionality - wrapped in ifdef so that it still
// compiles on other platforms
#ifdef ESP8266
extern "C" {
#include "user_interface.h"
}
#endif

ADC_MODE(ADC_VCC);

float currentVcc = 0.00f;
float analogValue=0.00f;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  delay(20);
  Serial.println("---- SERIAL TEST -----");
  Serial.print("FW Name: ");
  Serial.println(FW_NAME);
  Serial.print("FW Revision: ");
  Serial.println(FW_REVISION);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  currentVcc = system_get_vdd33();
  Serial.print("GetVcc: ");
  Serial.print(currentVcc);
  Serial.print(" => ");
  Serial.print(currentVcc/1024.00f);
  Serial.println(" V");

  analogValue = analogRead(A0);
  Serial.print("AnalogRead: ");
  Serial.print(analogValue);
   Serial.print(" => ");
  Serial.print(analogValue/1024.00f);
  Serial.println(" V");
  delay(1000);

}
