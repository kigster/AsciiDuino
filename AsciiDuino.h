/*
 * AsciiDuino.h
 *
 *  Created on: Aug 6, 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#ifndef ASCIIDUINO_H_
#define ASCIIDUINO_H_

#include <Arduino.h>
#include <Rainbowduino.h>

class AsciiDuino {
public:
	AsciiDuino(uint8_t matrixSize);
	void init(void);

	/*
	 * Draw a single frame defined by a string pattern.  "." in the patter is an empty
	 * cell, while "X" is the color cell. Only one color is currently supported per frame.
	 */
	void frame(const char* pattern, uint32_t color);

	/*
	 * Animate several frames passed in as an array, with a configurable 32-bit color and a delay
	 * between frames.
	 */
	void animate(const char *patterns[], uint8_t numOfPatterns, uint32_t color, uint16_t delay);

private:
	uint8_t _matrixSize;
};

#endif /* ASCIIDUINO_H_ */
