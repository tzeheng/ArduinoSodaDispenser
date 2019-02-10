// includes
#include <LiquidCrystal.h>

// initializing
const int rs=10, en=9, d4=5, d5=4, d6=3, d7=2, statusLED=8, valvePin = 11, pumpPin = 12, buttonPressedThresh=800;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
bool debug = true;

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
  int buttonPressed = analogRead(A0);
  if (buttonPressed > buttonPressedThresh) {
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
  Serial.println("Ready");
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
