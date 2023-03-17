#ifndef KEYBOARDBUTTONVIEW_H_
#define KEYBOARDBUTTONVIEW_H_

#include "ButtonView.h"

struct KeyBoardPosition
{
	int row, column;
};

class KeyBoardButtonView: public ButtonView
{
public:
	KeyBoardButtonView(TftDisplay *tft) :
			ButtonView(tft)
	{
		m_keyBoard_position.row = m_keyBoard_position.column = 0;
		m_selected = false;
		m_lastFrameColor = m_frameColor;
	}
	;
	void setKeyBoardPosition(int row, int column);
	KeyBoardPosition getKeyBoardPosition();
	virtual ~KeyBoardButtonView();
protected:
	KeyBoardPosition m_keyBoard_position;bool m_selected;
	unsigned int m_lastFrameColor;
};

#endif /* KEYBOARDBUTTONVIEW_H_ */
