#include "ButtonView.h"

ButtonView::~ButtonView()
{

}

int ButtonView::getTextHeight(){
	return TEXT_HEIGHT + FRAME_MARGIN;
}

void ButtonView::select(){
	Selectable::select();
	m_lastFrameColor = m_frameColor;
	setFrameColor(CYAN);
}

void ButtonView::deselect(){
	Selectable::deselect();
	setFrameColor(m_lastFrameColor);
}
