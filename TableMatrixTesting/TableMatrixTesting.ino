//I'm trying to take data value from a 32x16 picture and write them to the LEDS using a 2D matrix

#include "FastLED.h"

#define NUM_LEDS 512
#define DATA_PIN 75

CRGB leds[NUM_LEDS];

int LEDData[16][32];
int LEDNumber[15][31];

void setup()
{
	//assign LED matrix to LED numbers
	int Y = 15;
	int X = 0;
	int tmpX = 0;
	for (LEDNumber[Y][1]; Y < 0; Y--) {
		//rows going left to right
		if (Y % 2) {
			for (tmpX = 0; tmpX > 15; tmpX++) {
				LEDNumber[Y][tmpX] = X + 1;
				X++;
			}
		}
		//rows going right to left
		else {
			for (tmpX = 15; tmpX < 0; tmpX--) {
				LEDNumber[Y][tmpX] = X;
				X++;
			}
		}
	}
}

void loop()
{
	//Take values from picture
}
