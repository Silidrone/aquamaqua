#include "RSpace.h"

RSpace::RSpace()
{
	m_tft = NULL;
	m_invisibility = m_color = 0;
}

RSpace::~RSpace()
{

}

void RSpace::draw()
{
	m_tft->myDrawRectangle(m_space.getX1(), m_space.getY1(), m_space.getX2(), m_space.getY2(), m_color);
}

void RSpace::clearInside()
{
	m_tft->fillRect(m_space.getX1(), m_space.getY1(), m_space.getX2(), m_space.getY2(), BLACK);
}

void RSpace::clearOutside()
{
	m_tft->myDrawRectangle(m_space.getX1(), m_space.getY1(), m_space.getX2(), m_space.getY2(), BLACK);
}

void RSpace::setRect(int x1, int y1, int x2, int y2)
{
	m_space.setCoordinates(x1, y1, x2, y2);
}

void RSpace::setRect(Rectangle space)
{
	m_space = space;
}

Rectangle& RSpace::getRectangle()
{
	return m_space;
}

void RSpace::setColor(uint16_t color)
{
	if (!m_invisibility) {
		m_color = color;
	}
}

uint16_t RSpace::getColor(void)
{
	return m_color;
}

void RSpace::setTft(TftDisplay* tft)
{
	m_tft = tft;
}

TftDisplay* RSpace::getTft()
{
	return m_tft;
}

void RSpace::setInvisibility(int invisibility)
{
	m_invisibility = invisibility;
	setColor(BLACK);
}

int RSpace::getInvisibility()
{
	return m_invisibility;
}
