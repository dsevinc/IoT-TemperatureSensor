#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5
#define pwm_pin 3
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
void setup(void)
{
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  digitalWrite(pwm_pin,LOW);
  delay(500);
  digitalWrite(pwm_pin, HIGH);
  delay(100);
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(100);
}
