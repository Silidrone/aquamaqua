#ifndef TEXTVIEW_H_
#define TEXTVIEW_H_

#include "Window.h"
#include "Textable.h"

class TextView: public ViewBase, public Textable
{
public:
	TextView(TftDisplay *tft) :
			ViewBase(tft)
	{
		m_capsLock = false;
	}
	;
	virtual void draw();
	virtual void expandFrameForText();
	virtual void setText(String);
	virtual Rectangle calculateFrame(String);
	virtual void setCapsLock(bool);
protected:
	bool m_capsLock;
	String m_original_text;
};

#endif /* STATUS_H_ */
