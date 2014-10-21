#include "FastLED.h"

#define NUM_LEDS 38

#define DATA_PIN 13

CRGB leds[NUM_LEDS];
CHSV HSVleds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
	delay(2000);

	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
	srand(1024);
	for (int led = 0; led < NUM_LEDS; led++) {
		leds[led] = HSVleds[led] = CHSV(rand(), 255, 127);
	}
}

void loop() {
	for (int led = 0; led < NUM_LEDS; led++) {
		leds[led] = CHSV(HSVleds[led].hue++, 255, 127);
	}
	FastLED.show();
	delay(rand() % 10);
}
