#include "TftDisplay.h"

TftDisplay::~TftDisplay()
{
}

void TftDisplay::init()
{

//	tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
//tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
	tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	tft.fillScreen(ST7735_BLACK);
	//tft.setTextSize(1);
}

void TftDisplay::setTextSize(int textSize)
{
	m_textSize = textSize;
}

void TftDisplay::setTextWrap(int status)
{
	tft.setTextWrap(status);
}

void TftDisplay::text(String text, int x, int y, uint16_t color, int textSize)
{
	tft.setCursor(x, y);
	tft.setTextSize(textSize);
	tft.setTextColor(color, BLACK);
	tft.print(text);
}

void TftDisplay::text(String text, int x, int y, uint16_t color)
{
	tft.setCursor(x, y);
	tft.setTextSize(m_textSize);
	tft.setTextColor(color, BLACK);
	tft.print(text);
}

void TftDisplay::drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size){
	drawChar(x, y, c, color, bg, size);
}

void TftDisplay::fillRect(int x1, int y1, int x2, int y2, uint16_t color)
{
	tft.fillRect(x1, y1, abs(x2 - x1), abs(y2 - y1), color);
}

void TftDisplay::fillRect(const Rectangle& r, uint16_t color)
{
	fillRect(r.getX1(), r.getY1(), r.getX2(), r.getY2(), color);
}

void TftDisplay::myDrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color)
{
	tft.drawLine(x0, y0, x1, y1, color);
}

void TftDisplay::myDrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
	tft.drawPixel(x, y, color);
}

void TftDisplay::myDrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	tft.drawRect(x1, y1, abs(x2 - x1), abs(y2 - y1), color);
}

void TftDisplay::clearScreen()
{
	tft.fillRect(0, 0, TFTWIDTH, TFTHEIGHT, BLACK);
}

void TftDisplay::myDrawRectangle(Rectangle& r, uint16_t color)
{
	myDrawRectangle(r.getX1(), r.getY1(), r.getX2(), r.getY2(), color);
}

uint16_t TftDisplay::ConvertRGB(byte R, byte G, byte B)
{
	return (((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3));
}

