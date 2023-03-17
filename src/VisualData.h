#pragma once
#include "Arduino.h"
#include "TftDisplay.h"
#include "LinkedList.h"
#include "Rectangle.h"

struct point
{
	int x, y;
};

class VisualData
{
protected:
	LinkedList *m_recentData; // For deleting graph
	TftDisplay *m_tft;
	Rectangle m_frame;

	float m_maxValue, m_xDensity, m_yDensity, m_valueWidth;

	bool m_forceDraw;

	void displayGraphic(LinkedList *data, uint16_t color);
public:
	VisualData(TftDisplay *tft);
	~VisualData();

	void drawCompleteGraphic(LinkedList *data, uint16_t color);
	void drawBP(struct point point1, struct point point2, int xDensity, int yDensity, int limitZoneY, uint16_t color);

	void setMaxValue(float);
	float getMaxValue();

	void setValueWidth(int);
	int getValueWidth();

	void setXDensity(int);
	int getXDensity();

	void setYDensity(int);
	int getYDensity();

	void setForceDraw(bool);
	bool getForceDraw();

	void setTft(TftDisplay*);
	TftDisplay* getTft();

	void setFrame(int left, int top, int right, int bottom);
	void setFrame(Rectangle &r);
	Rectangle *getFrame();
};
