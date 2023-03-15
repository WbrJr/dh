//#define FASTLED_ALLOW_INTERRUPTS 0 //in case some sensors are not working - then the FastLED might be the problem because it takes too long to actually write each led
#include <FastLED.h>

#define NUM_LEDS 9
#define DATA_PIN 12

CRGB leds[NUM_LEDS]; //CRGB is a datatype created by fastled. it is basically and rgb colorspace. we create [num_leds] instances of the datatype crgb.

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); //sets the Type, pin, color-order
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < NUM_LEDS; i++){
    
    leds[i].setRGB(255, 0, 255); //set RGB values for specific led
    FastLED.show(); //renders the led color
    leds[i] = CRGB::Black;
    delay(50);
  }
}
