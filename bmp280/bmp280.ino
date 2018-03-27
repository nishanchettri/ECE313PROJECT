

#include <Wire.h>
#include <Adafruit_BMP280.h>


Adafruit_BMP280 bme; // I2C

  
void setup() {
  Serial.begin(9600);
  
  if (!bme.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");
int alt= bme.readAltitude(1013.25);
    Serial.print("Approx altitude = ");
    Serial.print(alt); // this should be adjusted to your local forcase
    Serial.println(" m");
    
    Serial.println();
    delay(2000);
}
