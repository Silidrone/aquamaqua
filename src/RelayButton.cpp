#include "RelayButton.h"

#define GAP 2

RelayButton::RelayButton(TftDisplay *tft) : ButtonView(tft)
{
	m_nameDesc = "Name: ";
	m_statusDesc = "Status: ";
	m_name = "DEFAULT";
	m_status = false;
}

int RelayButton::getTextHeight(){
	return TEXT_HEIGHT * 2 + GAP;
}

void RelayButton::setName(String name){
	m_name = name;
}

String RelayButton::getName(){
	return m_name;
}

void RelayButton::setStatus(bool status){
	m_status = status;
}

bool RelayButton::getStatus(){
	return m_status;
}

void RelayButton::toggleStatus(){
	setStatus(!m_status);
}

void RelayButton::draw(){
	auto text_position = getPosition();

	m_tft->text(m_nameDesc + m_name, text_position.x, text_position.y, (m_status ? GREEN : RED), 1);
	m_tft->text(m_statusDesc + (m_status ? String("ON") : String("OFF")), text_position.x, text_position.y + TEXT_HEIGHT + GAP, (m_status ? GREEN : RED), 1);
	drawFrame();
}

Rectangle RelayButton::calculateFrame(){
	Position start_pos = getPosition();
	Position end_pos = { start_pos.x + getTextWidth() + FRAME_MARGIN / 2, start_pos.y + getTextHeight() + FRAME_MARGIN / 2};
	return Rectangle (start_pos.x - FRAME_MARGIN / 2, start_pos.y - FRAME_MARGIN / 2, end_pos.x, end_pos.y);
}

void RelayButton::expandFrameForText(){
	setFrame(calculateFrame());
}

int RelayButton::getTextWidth(){
	int name_letter_count = m_nameDesc.length() + m_name.length();
	int status_letter_count = m_statusDesc.length() + ((m_status ? String("ON") : String("OFF")).length());
	return ((name_letter_count > status_letter_count) ? name_letter_count : status_letter_count) * TEXT_WIDTH;
}
