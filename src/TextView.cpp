#include "TextView.h"

void TextView::draw()
{
	if(m_capsLock){
		m_original_text = m_text;
		m_text.toUpperCase();
	} else {
		m_text = m_original_text;
	}

	auto text_position = getPosition();
	m_tft->text(getText(), text_position.x, text_position.y, m_textColor, 1);
	drawFrame();
}

void TextView::setText(String text){
	Textable::setText(text);
	m_original_text = text;
}

void TextView::expandFrameForText(){
	setFrame(calculateFrame(getText()));
}

void TextView::setCapsLock(bool capsLock){
	m_capsLock = capsLock;
}

Rectangle TextView::calculateFrame(String text)
{
	Position start_pos = getPosition();
	Position end_pos = { start_pos.x + (static_cast<int>(text.length()) * TEXT_WIDTH) + FRAME_MARGIN / 2, start_pos.y + TEXT_HEIGHT + FRAME_MARGIN / 2};

	return Rectangle (start_pos.x - FRAME_MARGIN / 2, start_pos.y - FRAME_MARGIN / 2, end_pos.x, end_pos.y);
}
