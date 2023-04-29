
#include <Wire.h>

#define PH_PIN A1
float voltage, phValue, temperature = 25;
float acidVoltage = 400;
float neutralVoltage = 354;
void setup() {
  Serial.begin(115200);

}

void loop() {
  static unsigned long timepoint = millis();
  if(millis()-timepoint>1000U) {
    timepoint = millis();
    voltage = analogRead(PH_PIN)/4095.0*3.3;
    float Offset = 0.38;
    //float slope = (8-7.6)/((neutralVoltage-354)/0.4 - (acidVoltage-354)/0.4);
    //float intercept = 8 - slope*(neutralVoltage-354)/0.4;
    phValue = 22.10*voltage+Offset;
   // phValue = slope*(voltage-354)/0.4+intercept;
    Serial.print("voltage");
    Serial.print(voltage,1);
    Serial.print(" pH");
    Serial.println(phValue,2);
  }

}
