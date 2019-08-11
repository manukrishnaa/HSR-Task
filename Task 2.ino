//Arduino program to monitor room temperature & light the LED
//when the temperature gets above a particular limit.


int SensorValue=0;
int LedPin=13;
float SensorPin=A0;
float Voltage=0;
float Temperature=0;

void setup()
{
  pinMode(LedPin, OUTPUT);
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  SensorValue=analogRead(SensorPin);   //Converting analog values into temperature values
  Voltage = (SensorValue * 5.0)/1024.0;
  Temperature = ((Voltage - 0.5) * 100);
  
  if(Temperature>28)
  {  
   digitalWrite(LedPin, HIGH);
   delay(1000);     //Delay of 1 second
  }    
  else
  {
   digitalWrite(LedPin, LOW);
   delay(1000);     //Delay of 1 second
  }
 }
