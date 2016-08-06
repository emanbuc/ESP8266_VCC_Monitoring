
/* ========= PRODUCT INFORMATION  =========== */
#define FW_REVISION 2
#define FW_NAME "Vcc monitoring"
/* -------------------- */
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
  
  currentVcc = ESP.getVcc();
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
