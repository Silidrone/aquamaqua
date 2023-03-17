#include "ViewBase.h"

ViewBase::ViewBase(TftDisplay *tft)
{
	m_tft = tft;
	m_frameColor = WHITE;
	m_frame.setCoordinates(0, 0, 0, 0);
}

/*ViewBase::ViewBase(ViewBase& other){
	m_frame = other.m_frame;
	m_frameColor = other.m_frameColor;
	m_tft = other.m_tft;
}*/

ViewBase::~ViewBase()
{
	// TODO Auto-generated destructor stub
}

void ViewBase::setFrame(int x1, int y1, int x2, int y2)
{
	m_frame.setCoordinates(x1, y1, x2, y2);
}

void ViewBase::setFrame(Rectangle frame)
{
	m_frame = frame;
}

void ViewBase::setPosition(int x, int y){
	m_position.x = x;
	m_position.y = y;
}

void ViewBase::setPosition(Position p){
	setPosition(p.x, p.y);
}

Position ViewBase::getPosition(){
	return m_position;
}

void ViewBase::setFrameColor(unsigned int color){
	m_frameColor = color;
}

Rectangle ViewBase::getFrame(){
	return m_frame;
}

void ViewBase::drawFrame(){
	m_tft->myDrawRectangle(m_frame, m_frameColor);
}

void ViewBase::eraseFrame(){
	m_tft->myDrawRectangle(m_frame, BLACK);
}

void ViewBase::eraseInsideFrame(){
	m_tft->fillRect(m_frame.getX1() + 1, m_frame.getY1() + 1, m_frame.getX2() - 1, m_frame.getY2() - 1, BLACK);
}
