#pragma once

#include "Rectangle.h"
#include "TftDisplay.h"

class RSpace
{
public:
	RSpace();
	~RSpace();

	void draw();
	void clearInside();
	void clearOutside();

	void setRect(int x1, int y1, int x2, int y2);
	void setRect(Rectangle space);
	Rectangle& getRectangle();

	void setInvisibility(int invisibility);
	int getInvisibility();

	void setColor(uint16_t color);
	uint16_t getColor(void);

	void setTft(TftDisplay*);
	TftDisplay* getTft();
protected:
	Rectangle m_space;
	int m_invisibility;
	uint16_t m_color;
	TftDisplay* m_tft;
};
