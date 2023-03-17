#ifndef INPUTBOXVIEW_H_
#define INPUTBOXVIEW_H_

#include "Arduino.h"
#include "ViewBase.h"

class InputBoxView: public ViewBase
{
public:
	InputBoxView(TftDisplay *tft) :
			ViewBase(tft)
	{
		setFrame(0, 0, 50, 20);
		m_text = "";
		m_textColor = WHITE;
		m_forceDraw = true;
	}
	;
	virtual ~InputBoxView();
	virtual void draw();
	void setText(String);
	void clearText();
	void appendText(String);
	void kickLastChar();
	String getText();
	void setDescription(String);
	String getDescription();
	void setTextColor(unsigned int);
	unsigned int getTextColor();
	void setForceDraw(bool b) { m_forceDraw = b; };
	bool getForceDraw() { return m_forceDraw; };
protected:
	String m_text;
	String m_description;
	unsigned int m_textColor;
	bool m_forceDraw;
};

#endif /* INPUTBOXVIEW_H_ */
