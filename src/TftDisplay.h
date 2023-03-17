#ifndef _TFTDISPLAY_h
#define _TFTDISPLAY_h

#include "Adafruit_GFX.h"    // Core graphics library
#include "Adafruit_ST7735.h"
#include <SPI.h>
#include "Rectangle.h"

#define TFT_CS     4
#define TFT_RST    5
#define TFT_DC     12
#define TFT_SCLK 14
#define TFT_MOSI 13

/*#define TFT_CS 26
 #define TFT_RST 24
 #define TFT_DC 25
 #define TFT_SCLK 22
 #define TFT_MOSI 23*/

//#define TFT_CS 10
//#define TFT_RST 8
//#define TFT_DC 9
//#define TFT_SCLK 22
//#define TFT_MOSI 23
/*#define TFT_CS   10
 #define TFT_DC   9
 #define TFT_RST  8
 #define TFT_SCLK 13   // set these to be whatever pins you like!
 #define TFT_MOSI 11*/// set these to be whatever pins you like!

#include "Colors.h"

/* TFT Dimensions */
#define TFTHEIGHT 160
#define TFTWIDTH 128
#define TEXT_HEIGHT 8
#define TEXT_WIDTH 6
#define FRAME_MARGIN 4

class TftDisplay
{
public:
	TftDisplay() :
			tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST)
	{
	}
	;
	~TftDisplay();

	void init();

	void setTextSize(int textSize);
	void setTextWrap(int status);

	void text(String text, int x, int y, uint16_t color, int textSize);
	void text(String text, int x, int y, uint16_t color);
	void drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);

	void fillRect(int x1, int y1, int x2, int y2, uint16_t color);
	void fillRect(const Rectangle &r, uint16_t color);
	void clearScreen();
	void myDrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
	void myDrawPixel(uint16_t x, uint16_t y, uint16_t color);
	void myDrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
	void myDrawRectangle(Rectangle &r, uint16_t color);
	void myFillRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
	uint16_t ConvertRGB(byte R, byte G, byte B);

protected:
	Adafruit_ST7735 tft;
	int m_textSize;
};

#endif
