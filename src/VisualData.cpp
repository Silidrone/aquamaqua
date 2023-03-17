#include "VisualData.h"

VisualData::VisualData(TftDisplay *tft)
{
	m_tft = tft;
	m_xDensity = 2;
	m_yDensity = 2;
	m_maxValue = 100;
	m_valueWidth = 20;
	m_recentData = new LinkedList();
	m_forceDraw = 0;
}

VisualData::~VisualData()
{
	delete m_recentData;
}

void VisualData::drawCompleteGraphic(LinkedList *data, uint16_t color)
{
	if (data->getCount() && !(data->isDirty()) && !m_forceDraw) {
		return;
	}

	displayGraphic(m_recentData, BLACK);
	displayGraphic(data, color);
	m_recentData->copyList(data);
	data->clean();
}

void VisualData::displayGraphic(LinkedList *data, uint16_t color)
{
	if (data->getCount() < 2) {
		return;
	}
	Rectangle newSpace;
	newSpace.setCoordinates(m_frame.getX1() + 1, m_frame.getY1() + 1, m_frame.getX2() - 3, m_frame.getY2() - 3);
	struct point point1, point2;
	int gap = round((float )(newSpace.getW()) / (m_valueWidth - 1));
	int spaceHeight = newSpace.getH();
	int x = newSpace.getX2();
	int y = newSpace.getY2();
	float unitY = spaceHeight / m_maxValue;
	for (Node *p = data->start->next; p->next != data->end; p = p->next, x -= gap) {
		point1.x = x;
		point1.y = y - (int) (p->value * unitY);
		point2.x = x - gap;
		point2.y = y - (int) (p->next->value * unitY);
		if ((p->next->next == data->end && data->getCount() == m_valueWidth) || point2.x < newSpace.getX1()) {
			point2.x = newSpace.getX1();
		}
		m_tft->myDrawLine(point1.x, point1.y, point2.x, point2.y, color);
		drawBP(point1, point2, 2, 2, y, color);
	}
}

void VisualData::drawBP(struct point point1, struct point point2, int xDensity, int yDensity, int limitZoneY, uint16_t color)
{
	float deltaX = point1.x - point2.x;
	float deltaY = point1.y - point2.y;
	for (float x = point1.x, y = point1.y; x >= point2.x; x -= xDensity, y -= (deltaY / deltaX) * xDensity) {
		for (int subY = y; subY <= limitZoneY; subY += yDensity) {
			m_tft->myDrawPixel((int) x, subY, color);
		}
	}
}

void VisualData::setMaxValue(float maxValue)
{
	m_maxValue = maxValue;
}

float VisualData::getMaxValue(void)
{
	return m_maxValue;
}

void VisualData::setValueWidth(int valueWidth)
{
	m_valueWidth = valueWidth;
}

int VisualData::getValueWidth(void)
{
	return m_maxValue;
}

void VisualData::setXDensity(int density)
{
	m_xDensity = density;
}

int VisualData::getXDensity()
{
	return m_xDensity;
}

void VisualData::setYDensity(int density)
{
	m_yDensity = density;
}

int VisualData::getYDensity()
{
	return m_yDensity;
}

void VisualData::setForceDraw(bool b)
{
	m_forceDraw = b;
}

bool VisualData::getForceDraw()
{
	return m_forceDraw;
}

void VisualData::setFrame(int left, int top, int right, int bottom)
{
	m_frame.setCoordinates(left, top, right, bottom);
}

void VisualData::setFrame(Rectangle &r)
{
	m_frame.setCoordinates(r.getX1(), r.getY1(), r.getX2(), r.getY2());
}
