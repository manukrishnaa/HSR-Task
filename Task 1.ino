String password="0000"; //Setting our initial password
String userinput;


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("Enter password");
  while (Serial.available()==0)  
  {                               
  }  
  userinput=Serial.readString();
  if(userinput==password)
   {
     Serial.print("Correct password");
    
     Serial.print("Date:");
     Serial.println(__DATE__);
    
     Serial.print("Current time:");
     Serial.println(__TIME__);
   }
  else
   {
    Serial.print("Incorrect password");
   } 
} 
