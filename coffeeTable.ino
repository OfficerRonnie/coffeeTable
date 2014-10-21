#include "FastLED.h"

#define NUM_LEDS 512

#define DATA_PIN 103

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
	delay(10000);

	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
	for (int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed++) {
		leds[whiteLed] = CRGB::White;

		FastLED.show();

		delay(100);

		leds[whiteLed] = CRGB::Black;
	}
}

