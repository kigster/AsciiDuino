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

void AsciiDuino::frame(const char* pattern, uint32_t color) {
	for (uint8_t x = 0; x < _matrixSize; x++) {
		for (uint8_t y = 0; y < _matrixSize; y++) {
			char c = pattern[x + y * _matrixSize];
			switch (c) {
			case 'X':
				Rb.setPixelXY(x, y, color);
				break;
			case '.':
				Rb.setPixelXY(x, y, (uint32_t) 0);
				break;
			}
		}
	}
}

void AsciiDuino::animate(const char *patterns[], uint8_t numOfPatterns,
		uint32_t color, uint16_t delayAmount) {
	for (uint8_t i = 0; i < numOfPatterns; i++) {
		frame(patterns[i], color);
		delay(delayAmount);
	}
}
