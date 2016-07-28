#pragma once

#include "Adafruit_NeoPixel.h"

class MycroftEyes {
public:
	enum Side {
		BOTH, LEFT, RIGHT
	};

	Adafruit_NeoPixel neoPixel;

	MycroftEyes(uint16_t size, uint8_t pin, uint16_t type);

	void setup();

	void on();

	void off();

	void blink(unsigned long wait, const char side);

	void narrow(unsigned long wait, const char side);

	void look(unsigned long wait, const char side);

	void updateColor(uint8_t r, uint8_t g, uint8_t b);

	void updateBrightness(uint8_t level);

	void set(Side side, uint32_t color);

	void set(uint32_t color);

private:
	uint32_t color;

	static bool leftOn(Side side);

	static bool rightOn(Side side);

	void blink(Side side, byte pos, byte leftJump, unsigned long wait);

	void narrow(Side side, byte pos, byte leftJump, unsigned long wait);

	void look(byte pos, byte leftJump, unsigned long wait);

	uint16_t mod(long a, long b);
};