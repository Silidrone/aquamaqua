#include "Rectangle.h"

Rectangle::Rectangle()
{
	m_x1 = m_y1 = m_x2 = m_y2 = m_w = m_h = 0;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	setCoordinates(x1, y1, x2, y2);
}

void Rectangle::setCoordinates(int x1, int y1, int x2, int y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
	m_w = abs(x2 - x1);
	m_h = abs(y2 - y1);
}

void Rectangle::setStartCoordinates(int x1, int y1){
	setCoordinates(x1, y1, m_x2, m_y2);
}

void Rectangle::setEndCoordinates(int x2, int y2){
	setCoordinates(m_x1, m_y1, x2, y2);
}

int Rectangle::getX1() const
{
	return m_x1;
}

int Rectangle::getY1() const
{
	return m_y1;
}

int Rectangle::getX2() const
{
	return m_x2;
}

int Rectangle::getY2() const
{
	return m_y2;
}

int Rectangle::getW() const
{
	return m_w;
}

int Rectangle::getH() const
{
	return m_h;
}

Rectangle Rectangle::operator+(Rectangle& rectangle)
{
	int new_x1 = rectangle.getX1() + this->getX1();
	int new_y1 = rectangle.getY1() + this->getY1();
	int new_x2 = rectangle.getX2() + this->getX2();
	int new_y2 = rectangle.getY2() + this->getY2();

	Rectangle resultRect;
	resultRect.setCoordinates(new_x1, new_y1, new_x2, new_y2);

	return resultRect;
}

void Rectangle::print(){
	// Serial.print("\tX1: ");
	// Serial.println(m_x1);

	// Serial.print("\tY1: ");
	// Serial.println(m_y1);

	// Serial.print("\tX2: ");
	// Serial.println(m_x2);

	// Serial.print("\tY2: ");
	// Serial.println(m_y2);
}
