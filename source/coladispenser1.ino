// includes
#include <LiquidCrystal.h>

// initializing
const int rs=11, en=10, d4=2, d5=3, d6=4, d7=5, statusLED=8, valvePin = 7, pumpPin = 6, buttonPressedThresh=800;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
bool debug = false;

void setup() {
  // serial output for logging and debugging
  if(debug){
    Serial.begin(9600);
    Serial.println("Initialization");
  }
  // initialize 16*2 LCD
  lcd.begin(16,2);
  lcd_print(1,"Soda Dispenser");
  lcd_print(2,"Initializing...");
  // set relay pins
  pinMode(valvePin,OUTPUT);
  pinMode(pumpPin,OUTPUT);
  pinMode(statusLED,OUTPUT);
  digitalWrite(valvePin, HIGH);
  digitalWrite(pumpPin, HIGH);
  // just in case
  delay(1000);
  if(debug)Serial.println("Ready");
  lcd_print(2,"Ready.");
  digitalWrite(statusLED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonPressed = digitalRead(13);
  if (buttonPressed) {
    dispense_cola();
  }
  delay(100);
}

// Dispense cycle
void dispense_cola(){
  if(debug)Serial.println("Dispensing Cycle");
  lcd_print(2,"Dispensing.");
  digitalWrite(statusLED, LOW);
  digitalWrite(valvePin, LOW);
  delay(500);
  digitalWrite(pumpPin, LOW);
  delay(3000);
  digitalWrite(pumpPin, HIGH);
  lcd_print(2,"Enjoy!");
  delay(500);
  digitalWrite(valvePin, HIGH);
  delay(1000);
  if(debug)Serial.println("Ready");
  lcd_print(2,"Ready.");
  digitalWrite(statusLED, HIGH);
}

//  LCD helper function
void lcd_print(int line, String outputString) {
  lcd.setCursor(0,line-1);
  lcd.print("                                        ");
  lcd.setCursor(0,line-1);
  lcd.print(outputString);
}

// Indicator status LED