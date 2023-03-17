#include "ViewNumeric.h"

ViewNumeric::~ViewNumeric()
{
	// TODO Auto-generated destructor stub
}

void ViewNumeric::draw()
{
	char value[20], status[20], name[20];
	sprintf(value, "Value: %3d", m_sensor->getQueriedValue());
	sprintf(status, "Status: %2d", m_sensor->getStatus());
	sprintf(name, "%s", m_sensor->getName().c_str());

	setFrameColor(GREEN);
	m_tft->setTextSize(m_textSize);
	m_tft->text(name, m_frame.getX1() + FRAME_MARGIN / 2, m_frame.getY1() + FRAME_MARGIN / 2, GREEN);
	m_tft->text(value, m_frame.getX1() + FRAME_MARGIN / 2, m_frame.getY1() + TEXT_HEIGHT * m_textSize + FRAME_MARGIN / 2, RED);
	m_tft->text(status, m_frame.getX1() + FRAME_MARGIN / 2, m_frame.getY1() + TEXT_HEIGHT * m_textSize * 2 + FRAME_MARGIN / 2, RED);
	drawFrame();
}

void ViewNumeric::setTextSize(int size){
	m_textSize = size;
}
