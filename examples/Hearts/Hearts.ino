/*
 * Rainbowduino-based Heart Animation
 *
 * Created on: Jul 30, 2014
 * Author: Konstantin Gredeskoul
 *
 * © 2014 All rights reserved.  Please see LICENSE.
 *
 */

#include <Rainbowduino.h>
#include <AsciiDuino.h>

AsciiDuino matrix(8);

const char *hearts[] = {
		".XX.XX.."
		"XXXXXXX."
		"XXXXXXX."
		".XXXXX.."
		"..XXX..."
		"...X...."
		"........"
		"........",

		"........"
		".XX.XX.."
		"XXXXXXX."
		"XXXXXXX."
		".XXXXX.."
		"..XXX..."
		"...X...."
		"........",

		"........"
		"........"
		".XX.XX.."
		"XXXXXXX."
		"XXXXXXX."
		".XXXXX.."
		"..XXX..."
		"...X....",

		"........"
		"........"
		"..XX.XX."
		".XXXXXXX"
		".XXXXXXX"
		"..XXXXX."
		"...XXX.."
		"....X...",

		"........"
		"..XX.XX."
		".XXXXXXX"
		".XXXXXXX"
		"..XXXXX."
		"...XXX.."
		"....X..."
		"........",


		"..XX.XX."
		".XXXXXXX"
		".XXXXXXX"
		"..XXXXX."
		"...XXX.."
		"....X..."
		"........"
		"........"
};

void setup() {
	matrix.init();
	srand(millis());
}

void loop() {
	matrix.animate(
			hearts,
			sizeof(hearts) / sizeof(char *),
			(uint32_t)((rand() % 8 + 1) * 0x100000), (uint16_t)1000);
}


