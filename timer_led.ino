#define sensorPin A0

int flag;


ISR(TIMER1_OVF_vect)
{
  if(flag==1)       //Checking Flag is set high
  {
    TCNT1=49910;    //Timer Preloading for 250 milliseconds
  }
  else if (flag==0) //Checking Flag is set low 
  {
    TCNT1=34285;    //Timer Preloading for 500 milliseconds
  }

  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle the LED
}
 
void setup()
{
  TCCR1A = 0;           // Init Timer1
  TCCR1B = 0;           // Init Timer1
  TCCR1B |= B00000100;  // Prescalar = 256
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt
  pinMode(LED_BUILTIN, OUTPUT); // set LED pin to OUTPUT
  Serial.begin(9600);
}
void loop()
{
   
  int reading = analogRead(sensorPin);       // Get the voltage reading from the LM35

  
  float voltage = reading * (5.0 / 1024.0);  // Convert that reading into voltage

  
  float temperatureC = voltage * 100;        // Convert the voltage into the temperature in Celsius
  

  Serial.print("Temperature: ");             // Print the temperature in Celsius
  Serial.println(temperatureC);
  
 
 if(temperatureC<30)                         //Checking if Temperature falls below 30 degrees Celsius
  {
    flag=1;                                  //Setting flag high
  }
 
  else if(temperatureC>30)                   //Checking if temperature rises above 30 degrees Celsius
  {
    
    flag=0;                                  //Setting flag low
   
  }
}
