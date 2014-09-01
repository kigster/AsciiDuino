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

RGBColor red = { {128, 0, 0 }};

/*
 * Call back that is called every time a pixel is drawn. Adds variation to the
 * primary color.
 */
RGBColor modifyColor(uint8_t x, uint8_t y, char value, RGBColor previousColor) {
	RGBColor c = previousColor;
	for (int i = 0; i < 3; i++) {
		if (c.rgb[i] > 0) {
			c.rgb[i] = c.rgb[i] + rand() % 32;
		}
	}
	return c;
}

void setup() {
	matrix.init();
}

void loop() {
	matrix.animate(
			hearts,
			sizeof(hearts) / sizeof(char *),
			red,
			1000,
			&modifyColor);
}


