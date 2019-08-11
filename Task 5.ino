//Including the respective header files

#include <LiquidCrystal.h>
#include <keypad.h> 

#define redLED 10
#define greenLED 11

char* password ="0000"; //Our initial password
int position = 0;

const byte rows = 4; //number of the keypad's rows 
const byte cols = 4; //number of the keypad's and columns

char keyMap [rows] [cols] =     //Defining the keys of the keyboard
{ 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins [rows] = {1, 2, 3, 4}; //pins of the keypad
byte colPins [cols] = {5, 6, 7, 8};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // Analog inputs of the LCD

void setup(){

  lcd.begin(16, 2); //No. of rows and columns on the LCD
  lcd.setCursor(0, 0);
  lcd.print(" Enter Password");
}

void loop(){

  char userKey = myKeypad.getKey(); //define which key is pressed with getKey

  if(userKey == '*' || userKey == '#' || userKey == 'A' || userKey == 'B' || userKey== 'C' || userKey == 'D')
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Invalid Key!");
    delay(5000);
    lcd.clear();
  }
  int i=0;
  if(userKey == password [i])
  {
    i++;
  }
  if(i == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Correct password");
    delay(5000);
    lcd.clear();  
  }
  delay(10000);
}
