/*
 * display.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Saheblal Bagwan
 */

#include "tft.h"
#include "stdio.h"
#include "string.h"
#include "lib_ota.h"
#include "lib_delay.h"
#include "lib_system.h"

ili9341_t *_lcd;
extern SPI_HandleTypeDef hspi1;
ili9341_t *display(void)
{
    return _lcd;
}

void tft_init()
{
    _lcd = ili9341_new(&hspi1,
                       GPIOA, GPIO_PIN_4, // Reset
                       GPIOC, GPIO_PIN_4, // CS
                       GPIOC, GPIO_PIN_5, // DC
                       isoLandscape,
                       GPIOD, 0,
                       GPIOD, 0, itsNotSupported, itnNONE);
}

void tft_drawRectangle(ili9341_color_t color, int x, int y, int w, int h)
{
    ili9341_draw_rect(_lcd, color, x, y, w, h);
}

void tft_fillRectangle(ili9341_color_t color, int x, int y, int w, int h)
{
    ili9341_fill_rect(_lcd, color, x, y, w, h);
}

void tft_print(ili9341_font_t const *pFont, ili9341_color_t fgColor, ili9341_color_t bgColor, uint16_t x, uint16_t y,
               char *text)
{
    ili9341_text_attr_t textAttr = (ili9341_text_attr_t){.font = pFont, .fg_color = fgColor, .bg_color = bgColor, .origin_x = x, .origin_y = y};
    int w = strlen(text) * pFont->width;
    int h = pFont->height;
    ili9341_fill_rect(_lcd, bgColor, x, y, w, h);
    ili9341_draw_string(_lcd, textAttr, text);
}

void tft_printCenter(ili9341_font_t const *pFont, ili9341_color_t fgColor, ili9341_color_t bgColor, uint16_t y,
                     char *text)
{

    int w = strlen(text) * pFont->width;
    int h = pFont->height;
    int x = (320 - w) / 2;
    ili9341_text_attr_t textAttr = (ili9341_text_attr_t){.font = pFont, .fg_color = fgColor, .bg_color = bgColor, .origin_x = x, .origin_y = y};

    ili9341_fill_rect(_lcd, bgColor, x, y, w, h);
    ili9341_draw_string(_lcd, textAttr, text);
}

static void tft_header(char *hdr, char *ftr)
{
    tft_drawRectangle(ILI9341_CYAN, 0, 0, DEFAULT_TFT_DISPLAY_WIDTH, 24);
    tft_fillRectangle(ILI9341_BLACK, 1, 1, DEFAULT_TFT_DISPLAY_WIDTH - 2, 24 - 2);

    tft_drawRectangle(ILI9341_CYAN, 0, 200, DEFAULT_TFT_DISPLAY_WIDTH, 24);
    tft_fillRectangle(ILI9341_BLACK, 1, 201, DEFAULT_TFT_DISPLAY_WIDTH - 2, 24 - 2);

    if (hdr)
    {
        tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 4, hdr);
    }

    if (ftr)
    {
        tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 202, ftr);
    }
}

void tft_displayCounter(uint16_t count)
{
    char str[50] = {0};
    sprintf(str, "%03d", count);
    tft_printCenter(&ili9341_font_16x26, ILI9341_ORANGE, ILI9341_BLACK, 130, str);
}

void tft_displayProgress()
{
    char str[50] = {0};
    static uint32_t count = 0, tempCount = 99;
    static uint32_t countIncrementDelay = 0;

    if (DEVICE_STATE_OTA == SYSTEM_getmode())
    {
        count = OTA_getProgressPercentage();
        if (tempCount != count)
        {
            tempCount = count;
            if (count)
            {
                sprintf(str, "%0d%%", (int)count);
                tft_fillRectangle(ILI9341_GREEN, 50, 132, count * 2, 20);
                tft_print(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 260, 134, str);

                if (100 == count)
                {
                    delay(500);
                    count = 0xFFFF;
                    tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 80, "                ");
                    tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 100, "                ");
                    tft_fillRectangle(ILI9341_BLACK, 0, 130, 320, 24);
                    tft_printCenter(&ili9341_font_16x26, ILI9341_DARKGREEN, ILI9341_BLACK, 90, "Rebooting...");
                }
            }
            else
            {
                tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 80, "                ");
                tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 100, "                ");
                tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 90, "Downloading File");
                tft_drawRectangle(ILI9341_LIGHTGREY, 48, 130, 204, 24);
                tft_fillRectangle(ILI9341_BLACK, 50, 131, 200, 20);
            }
        }
    }
    else
    {
        if (0xFFFF > count)
        {
            if (!count)
            {
                // tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 80, "Waiting for");
                // tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 100, "Serial Download");
                // tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 80, "FW Version");
                // tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 100, fwVersion);
                // sprintf(str, "Firmware v%s", fwVersion);
                tft_printCenter(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 90, "Hello World !");
            }
            if (millis() > countIncrementDelay)
            {
                countIncrementDelay = millis() + 1000;
                tft_displayCounter(count++);
            }
        }
    }
}

void tft_welcomeScreen(char *fwVersion)
{
    char str[50] = {0};
    ili9341_fill_screen(_lcd, ILI9341_BLACK);
    tft_header("STM32 BOOTLOADER", "BuildStorm Technologies");
    sprintf(str, "v%s         App Size:%d", fwVersion, (int)FLASH_getAppSize());
    tft_print(&ili9341_font_11x18, ILI9341_LIGHTGREY, ILI9341_BLACK, 0, 28, str);
}
