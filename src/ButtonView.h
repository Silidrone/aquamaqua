#ifndef BUTTONVIEW_H_
#define BUTTONVIEW_H_

#include "TextView.h"
#include "Selectable.h"

class ButtonView: public TextView, public Selectable
{
public:
	ButtonView(TftDisplay *tft) :
			TextView(tft)
	{
		m_textColor = ORANGE;
		m_frameColor = YELLOW;
		m_lastFrameColor = m_frameColor;
	}
	;
	static int getTextHeight();
	virtual ~ButtonView();
	virtual void select();
	virtual void deselect();
protected:
	unsigned int m_lastFrameColor;
};

#endif /* BUTTONVIEW_H_ */
