//ARDUINO CODE FOR THE SMART STEP 
//FIRST INSTALL THE FastLED.h and NewPing.h libraries
//Assemble the project just like from the tinkerCAD

#include <FastLED.h>
#include <NewPing.h>

//For the LED STRIP
#define NUM_LEDS 224
#define LED_PIN 3
CRGB leds[NUM_LEDS];

//For the Sensors
#define MaxDistance 100
#define trigPin 2
#define echo0 12
#define echo1 4
#define echo2 5
#define echo3 6
#define echo4 7
#define echo5 8
#define echo6 9
#define echo7 10
#define echo8 11


NewPing  sen0(trigPin, echo0, MaxDistance);
NewPing  sen1(trigPin, echo1, MaxDistance);
NewPing  sen2(trigPin, echo2, MaxDistance);
NewPing  sen3(trigPin, echo3, MaxDistance);
NewPing  sen4(trigPin, echo4, MaxDistance);
NewPing  sen5(trigPin, echo5, MaxDistance);
NewPing  sen6(trigPin, echo6, MaxDistance);
NewPing  sen7(trigPin, echo7, MaxDistance);
NewPing  sen8(trigPin, echo8, MaxDistance);
float D0,D1,D2,D3,D4,D5,D6,D7,D8;


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
}

void loop() { 
 
  sense();

  EVERY_N_MILLISECONDS(200){
  fadeToBlackBy(leds, NUM_LEDS, 40);  // This is the method to dim the lights
  }

  //The length of the stairs in my house is 60 cm
  //The sensor can detect that 60cm and it is not that accurate
  //that is why we decided to adjust the limit to 57
  if(D0 < 57 && D0 > 2){
    red(0,56);
  }

  if(D1 < 57 && D1 > 2){
   red(0,84);
  }

  if(D2 < 57 && D2 > 2){
   red(28,112);
  }

  if(D3 < 57 && D3 > 2){
   red(56,140);
  }

  if(D4 < 57 && D4 > 2){
   red(84,168);
  }

  if(D5 < 57 && D5 > 2){
   red(112,196);
  }

  if(D6 < 57 && D6 > 2){
   red(140,224);
  }

  if(D7 < 57 && D7 > 2){
   red(168,224);
  }

  if(D8 < 57 && D8 > 2){
   red(196,224);
  }
  FastLED.show();
}


// For sensing a disturbance within the environment
void sense(){
  D0 = sen0.ping_cm();
  D1 = sen1.ping_cm();
  D2 = sen2.ping_cm();
  D3 = sen3.ping_cm();
  D4 = sen4.ping_cm();
  D5 = sen5.ping_cm();
  D6 = sen6.ping_cm();
  D7 = sen7.ping_cm();
  D8 = sen8.ping_cm();

  Serial.print("0: "); Serial.print(D0);
  Serial.print("  1: ");  Serial.print(D1);
  Serial.print("  2: ");  Serial.print(D2);
  Serial.print("  3: ");  Serial.print(D3);
  Serial.print("  4: ");  Serial.print(D4);
  Serial.print("  5: ");  Serial.print(D5);
  Serial.print("  6: ");  Serial.print(D6);
  Serial.print("  7: ");  Serial.print(D7);
  Serial.print("  8: ");  Serial.println(D8);
}


//method used to light up a certain set of led Strip
void red(int starter, int ender){
  EVERY_N_MILLISECONDS(200){
    for(int a = starter; a<ender; a++) leds[a] = CRGB::Red;
    }
}
