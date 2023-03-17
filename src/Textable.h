#ifndef TEXTABLE_H_
#define TEXTABLE_H_

#include "Arduino.h"
#include "Colors.h"

class Textable
{
public:
	Textable() {
		m_text = "";
		m_textColor = WHITE;
	};
	virtual ~Textable();
	virtual void setText(String text);
	virtual String getText();
	virtual void setTextColor(unsigned int);
protected:
	String m_text;
	unsigned int m_textColor;
};

#endif
