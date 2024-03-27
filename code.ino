#include <TimedBlink.h>
// Define the analog pin, the LM35's Vout pin is connected to
#define sensorPin A0

TimedBlink monitor(LED_BUILTIN);
void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Get the voltage reading from the LM35
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = voltage * 100;
  

  // Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.println(temperatureC);
 //Checking if Temperature falls below 30 degrees Celsius
  if(temperatureC<30)
  {
    //Led blinks at every  250 ms
    monitor.blink(250,250);
  }
 //Checking if temperature rises above 30 degrees Celsius
  else if(temperatureC>30)
  {
    //Led blinks at every 500 ms
    monitor.blink(500,500);  
  }

  
  
  
  

  //monitor.blinkDelay(1000); // wait a second between readings
}
