#include <Adafruit_NeoPixel.h>

#define PIN 3	 // input pin Neopixel is attached to

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

#define NUMPIXELS      24 // number of neopixels in Ring

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int counter;

void setup()
{
  pinMode(PIN, OUTPUT);
  pixels.begin();
}

void loop()
{
 
 
  setColor();
  for(int i=0;i<NUMPIXELS;i++){
//    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
   pixels.setPixelColor(i, pixels.Color(0,20,0));
    // pixels.setPixelColor(i, pixels.Color(random(0, 255), random(0, 255), random(0, 255)));
  }  
  pixels.show();
  delay(100); // Wait for 1000 millisecond(s)
}

void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
}
