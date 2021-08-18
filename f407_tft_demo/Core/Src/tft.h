/*
 * display.h
 *
 *  Created on: Jul 31, 2021
 *      Author: Saheblal Bagwan
 */

#ifndef SRC_TFT_H_
#define SRC_TFT_H_

#include "ili9341.h"
#include "ili9341_gfx.h"

#define DEFAULT_TFT_DISPLAY_WIDTH 320
#define DEFAULT_TFT_DISPLAY_HEIGHT 240

void tft_init();
ili9341_t *display(void);
void tft_print(ili9341_font_t const *pFont,ili9341_color_t fgColor,ili9341_color_t bgColor, uint16_t x, uint16_t y, char *text );
void tft_welcomeScreen(char *fwVersion);
void tft_displayCounter(uint16_t count);
void tft_displayProgress();
#endif /* SRC_TFT_H_ */
