#ifdef ADDRESSABLE_LED
#include <FastLED.h>
CRGB leds[NUM_LEDS];
#endif

// what to do about multiled support
#define NUM_LEDS 1

#if defined(ARDUINO_M5Stack_ATOM) // should add and statements for led build flag
#define DATA_PIN 27
#elif defined(ARDUINO_M5Stack_ATOMS3)
#define DATA_PIN 35
#elif defined(ARDUINO_M5Stick_C)
#define DATA_PIN 19
#elif defined(ARDUINO_M5Stack_StampS3)
#define DATA_PIN 21
#elif defined(ARDUINO_ESP32_DEV) && defined(LED)
#define BUILTIN 2
#elif defined(ARDUINO_NANO_ESP32) && defined(RGB_LED)
// i'm not sure if this runs, have to check ARDUINO_NANO_ESP32 and same for regular esp32
#define RED_PIN 14
#define GREEN_PIN 15
#define BLUE_PIN 16
#endif


void ledcolor(uint32_t colorcode) {
  #ifdef ADDRESSABLE_LED
  /*
   * What if we had more than 1 led?
   * for(int num=0; num<NUM_LEDS; num++) {
   *  leds[num] = CRGB(colorcode);
   * }
   */

  leds[0] = CRGB(colorcode);
  FastLED.show();
  // We are supposed to wait this long but I don't want to.
  // delay(50)
  #endif

  #ifdef RGB_LED
  digitalWrite(15, HIGH);
  #endif
}

void rfhsledinit() {
  #ifdef ADDRESSABLE_LED
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  // M5Stack recommends not setting this value greater than 20
  // to avoid melting the screen/cover over the LEDs
  FastLED.setBrightness(20);
  #endif

  #ifdef RGB_LED
  //pinMode(RED_LED, OUTPUT);
  //pinMode(GREEN_LED, OUTPUT);
  //pinMode(BLUE_LED, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  #endif

  #ifdef LED
  pinMode(BUILTIN, OUTPUT);
  #endif
}
