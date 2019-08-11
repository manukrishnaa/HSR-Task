//Arduino program to control 4 DC Motors using a pushbutton.
//The motors are functional as long as the pushbutton is pressed.


int SwitchPin=3;
boolean LastButton=LOW;
boolean CurrentButton=LOW;
boolean MotorState=false;
int M1EPin=12;
int M2EPin=13;
int M3EPin=8;
int M4EPin=7;

int M1In1Pin=6;
int M1In2Pin=9;

int M2In1Pin=10;
int M2In2Pin=11;

int M3In1Pin=1;
int M3In2Pin=2;

int M4In1Pin=4;
int M4In2Pin=5;

boolean debounce(boolean last)   //Debounce function
{
  boolean current= digitalRead(SwitchPin);
  if (last!=current)
  {
   delay(5);
   current= digitalRead(SwitchPin);
  }
  return current;
}
 

void setup()
{
  pinMode(SwitchPin, INPUT); //Switch
  
  //Right Bridge
  pinMode(M1EPin, OUTPUT);  //M1
  pinMode(M1In1Pin, OUTPUT);
  pinMode(M1In2Pin, OUTPUT);
  digitalWrite(M1EPin, HIGH);
  
  pinMode(M2EPin, OUTPUT);  //M2
  pinMode(M2In1Pin, OUTPUT);
  pinMode(M2In2Pin, OUTPUT);
  digitalWrite(M2EPin, HIGH);
  
  //Left Bridge
  pinMode(M3EPin, OUTPUT);  //M3
  pinMode(M3In1Pin, OUTPUT);
  pinMode(M3In2Pin, OUTPUT);
  digitalWrite(M3EPin, HIGH);
  
  pinMode(M4EPin, OUTPUT);  //M4
  pinMode(M4In1Pin, OUTPUT);
  pinMode(M4In2Pin, OUTPUT);
  digitalWrite(M4EPin, HIGH);
}

void loop()
{
  CurrentButton=debounce(LastButton);          //For debouncing
  if(LastButton==LOW && CurrentButton==HIGH)   //Motor is activted only while button is pressed.
  {
  digitalWrite(M1In1Pin, HIGH);  //M1
  digitalWrite(M1In2Pin, LOW);
  
  digitalWrite(M2In1Pin, HIGH);  //M2
  digitalWrite(M2In2Pin, LOW);
  
  digitalWrite(M3In1Pin, HIGH);  //M3
  digitalWrite(M3In2Pin, LOW);
  
  digitalWrite(M4In1Pin, HIGH);  //M4
  digitalWrite(M4In2Pin, LOW);
  }
  else
  {
  digitalWrite(M1In1Pin, LOW);  //M1
  digitalWrite(M1In2Pin, LOW);
  
  digitalWrite(M2In1Pin, LOW);  //M2
  digitalWrite(M2In2Pin, LOW);
  
  digitalWrite(M3In1Pin, LOW);  //M3
  digitalWrite(M3In2Pin, LOW);
  
  digitalWrite(M4In1Pin, LOW);  //M4
  digitalWrite(M4In2Pin, LOW); 
  }
} 
  
