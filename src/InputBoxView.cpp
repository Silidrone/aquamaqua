#include "InputBoxView.h"

InputBoxView::~InputBoxView()
{

}

void InputBoxView::draw()
{
	if (m_forceDraw) {
		eraseInsideFrame();
		m_tft->text(m_description + ": ", m_frame.getX1(), m_frame.getY1() - 11, m_textColor);
		m_tft->myDrawRectangle(m_frame.getX1(), m_frame.getY1(), m_frame.getX2(), m_frame.getY2(), m_frameColor);
		m_tft->text(m_text, m_frame.getX1() + 2, ((m_frame.getY1() + m_frame.getY2()) / 2) - 2, m_textColor);
		m_forceDraw = false;
	}
}

void InputBoxView::setText(String text)
{
	if (m_frame.getX1() + 2 + TEXT_WIDTH * text.length()) {
		m_text = text;
	}
	m_forceDraw = true;
}

void InputBoxView::clearText(){
	m_text = "";
	m_forceDraw = true;
}

void InputBoxView::appendText(String text)
{
	if (m_frame.getX1() + 2 + (TEXT_WIDTH * (m_text.length() + text.length())) <= m_frame.getX2() - 2) {
		m_text += text;
	}
	m_forceDraw = true;
}

void InputBoxView::kickLastChar()
{
	m_text.remove(m_text.length() - 1);
	m_forceDraw = true;
}

String InputBoxView::getText()
{
	return m_text;
}

void InputBoxView::setTextColor(unsigned int textColor)
{
	m_textColor = textColor;
	m_forceDraw = true;
}

unsigned int InputBoxView::getTextColor()
{
	return m_textColor;
}

void InputBoxView::setDescription(String description)
{
	m_description = description;
}

String InputBoxView::getDescription()
{
	return m_description;
}
