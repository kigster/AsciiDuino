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


// Various thresholds that trigger sensors
typedef struct colorStruct {
	uint8_t rgb[3];
} RGBColor;

typedef RGBColor(*drawPixelCallback)(const uint8_t x, const uint8_t y, const char value, const RGBColor color);

class AsciiDuino {
public:
	AsciiDuino(uint8_t matrixSize);
	void init(void);

	/*
	 * Draw a single frame defined by a string pattern.  "." in the pattern is an empty
	 * cell, while "X" is the color cell. Only one color is currently supported per frame.
	 */
	void frame(const char* pattern, RGBColor color);

	/*
	 * Allows passing a callback function that has a chance to modify color of the pixel
	 * before it is drawn.
	 */
	void frame(const char* pattern, RGBColor color, drawPixelCallback callback);

	/*
	 * Animate several frames passed in as an array, with a configurable 32-bit color and a delay
	 * between frames.
	 */
	void animate(const char *patterns[], uint8_t numOfPatterns, RGBColor color, uint16_t delay);
	/*
	 * And with callback to optionally modify colors.
	 */
	void animate(const char *patterns[], uint8_t numOfPatterns, RGBColor color, uint16_t delay, drawPixelCallback callback);

	uint32_t rgbToInt(RGBColor color);
private:
	uint8_t _matrixSize;
};

#endif /* ASCIIDUINO_H_ */
