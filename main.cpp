#include <Arduino.h>
#include "Time.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Fonts/FreeSansBold9pt7b.h"
#include "Fonts/Org_01.h"
#include "Adafruit_SSD1306.h"

#define PAUSE 3000 // How long to delay?

#define LED01 2
#define LED02 3
#define LED03 4
#define LED04 5
#define LED05 6

int LEDone = LED01;
int LEDtwo = LED02;
int LEDthree = LED03;
int LEDfour = LED04;
int LEDfive = LED05;

const int BZR01 = 8;
const int BZR02 = 9;
const int BZR03 = 10;
const int BZR04 = 11;
const int BZR05 = 12;


long randomNumber = 0L; // Use the "L" to tell compiler it's a long data type, not an int.

Adafruit_SSD1306 display(128, 64, &Wire, 8); //Declaring the display name (display)

void setup()
{
  randomSeed(analogRead(0)); // This seeds the random number generator

  // initialize each of the digital pins as an output.
  pinMode(LEDone, OUTPUT);
  pinMode(LEDtwo, OUTPUT);
  pinMode(LEDthree, OUTPUT);
  pinMode(LEDfour, OUTPUT);
  pinMode(LEDone, OUTPUT);
  pinMode(LEDfive, OUTPUT);
  pinMode(BZR01, OUTPUT);
  pinMode(BZR02, OUTPUT);
  pinMode(BZR03, OUTPUT);
  pinMode(BZR04, OUTPUT);
  pinMode(BZR05, OUTPUT);
  noTone(BZR01);
  noTone(BZR02);
  noTone(BZR03);
  noTone(BZR04);
  noTone(BZR05);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();
  display.setFont(&FreeSansBold9pt7b);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 15);
  display.println("   Random-5"); //Show the name, you can remove it or replace it
  display.setCursor(25, 38);
  display.setTextSize(1);
  display.println("Monster");
  display.setCursor(2, 52);
  display.println("  Laboratories");
  display.display();
  delay(3000);
  
  for (int16_t i = 0; i < display.height() / 10; i += 3)
  {
    // The INVERSE color is used so rectangles alternate white/black
    display.fillRect(i, i, display.width() - i * 2, display.height() - i * 2, INVERSE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }
}

long generateRandomNumber()
{  
  return random(0, 1000000); // Generate random numbers between 0 and one million
}

void loop()
{
  // Start with lights off.
  digitalWrite(LEDone, LOW);
  digitalWrite(LEDtwo, LOW);
  digitalWrite(LEDthree, LOW);
  digitalWrite(LEDfour, LOW);
  digitalWrite(LEDfive, LOW);
  noTone(BZR01);
  noTone(BZR02);
  noTone(BZR03);
  noTone(BZR04);
  noTone(BZR05);

  randomNumber = generateRandomNumber();

  display.clearDisplay();
  display.setFont(&Org_01);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 12);
  display.println("Random Number:");
  display.display();
  display.setCursor(10, 40);
  display.setTextSize(3);
  display.println(randomNumber); //Show the name, you can remove it or replace it
  display.display();

   if (randomNumber % 2 == 1) //If there's a remainder, it's odd.
  {
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, LOW);
    digitalWrite(LEDthree, LOW);
    digitalWrite(LEDfour, LOW);
    digitalWrite(LEDfive, LOW);
    tone(BZR01, 41, 100);
    delay(1000);
  }

   if (randomNumber % 2 == 0) //Is it even? (Divisible by 2 without remainder ?)
  {
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, LOW);
    digitalWrite(LEDfour, LOW);
    digitalWrite(LEDfive, LOW);
    tone(BZR02, 90, 100);
    delay(1000);
  }


  if (randomNumber % 3 == 0)
    {
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, HIGH);
    digitalWrite(LEDfour, LOW);
    digitalWrite(LEDfive, LOW);
    tone(BZR03, 120, 100);
    delay(1000);
    }

  if (randomNumber % 4 == 0)

   {   
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, HIGH);
    digitalWrite(LEDfour, HIGH);
    digitalWrite(LEDfive, LOW);
    tone(BZR04, 750, 100);
    delay(1000);
}

  if (randomNumber % 5 == 0)
  { 
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, HIGH);
    digitalWrite(LEDfour, HIGH);
    digitalWrite(LEDfive, HIGH);
    tone(BZR05, 1250, 100);
  }
  delay(PAUSE);

  if (randomNumber == 0 || randomNumber == 1) // Is it a prime number?

  {
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, HIGH);
    digitalWrite(LEDfour, HIGH);
    digitalWrite(LEDfive, HIGH);
    tone(BZR01, 300, 500);
    tone(BZR02, 500, 500);
    tone(BZR03, 700, 500);
    tone(BZR04, 900, 500);
    tone(BZR05, 1100, 500);
    delay(500);
    digitalWrite(LEDone, LOW);
    digitalWrite(LEDtwo, LOW);
    digitalWrite(LEDthree, LOW);
    digitalWrite(LEDfour, LOW);
    digitalWrite(LEDfive, LOW);
    noTone(BZR01);
    noTone(BZR02);
    noTone(BZR03);
    noTone(BZR04);
    noTone(BZR05);
    delay(500);
    digitalWrite(LEDone, HIGH);
    digitalWrite(LEDtwo, HIGH);
    digitalWrite(LEDthree, HIGH);
    digitalWrite(LEDfour, HIGH);
    digitalWrite(LEDfive, HIGH);
    tone(BZR01, 300, 500);
    tone(BZR02, 500, 500);
    tone(BZR03, 700, 500);
    tone(BZR04, 900, 500);
    tone(BZR05, 1100, 500);
    delay(500);
    digitalWrite(LEDone, LOW);
    digitalWrite(LEDtwo, LOW);
    digitalWrite(LEDthree, LOW);
    digitalWrite(LEDfour, LOW);
    digitalWrite(LEDfive, LOW);
    noTone(BZR01);
    noTone(BZR02);
    noTone(BZR03);
    noTone(BZR04);
    noTone(BZR05);
  }
}