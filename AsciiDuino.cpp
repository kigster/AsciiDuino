/*
 * AsciiDuino.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#include "AsciiDuino.h"

AsciiDuino::AsciiDuino(uint8_t matrixSize) {
	_matrixSize = matrixSize;
}

void AsciiDuino::init(void) {
	Rb.init();
}

void AsciiDuino::frame(const char* pattern, RGBColor color) {
	frame(pattern, color, (drawPixelCallback) NULL);
}

void AsciiDuino::frame(const char* pattern, RGBColor color, drawPixelCallback callback) {
	uint32_t c = rgbToInt(color);
	for (uint8_t x = 0; x < _matrixSize; x++) {
		for (uint8_t y = 0; y < _matrixSize; y++) {
			char ch = pattern[x + y * _matrixSize];
			if (callback != NULL) {
				RGBColor newColor = callback(x, y, ch, color);
				Rb.setPixelXY(x, y, rgbToInt(newColor));
			} else {
				switch (ch) {
				case 'X':
					Rb.setPixelXY(x, y, c);
					break;
				case '.':
					Rb.setPixelXY(x, y, (uint32_t) 0);
					break;
				}
			}
		}
	}
}

void AsciiDuino::animate(const char *patterns[], uint8_t numOfPatterns,
		RGBColor color, uint16_t delayAmount, drawPixelCallback callback) {
	for (uint8_t i = 0; i < numOfPatterns; i++) {
		frame(patterns[i], color, callback);
		delay(delayAmount);
	}
}

void AsciiDuino::animate(const char *patterns[], uint8_t numOfPatterns,	RGBColor color, uint16_t delayAmount) {
	animate(patterns, numOfPatterns, color, delayAmount, NULL);
}

uint32_t AsciiDuino::rgbToInt(RGBColor color) {
	return (0x010000 * (uint32_t) color.rgb[0] + 0x000100 * (uint32_t) color.rgb[1] + 0x000001 * (uint32_t) color.rgb[2]);
}
