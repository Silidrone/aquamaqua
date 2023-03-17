#ifndef LISTBUTTONVIEW_H_
#define LISTBUTTONVIEW_H_

#include "ButtonManager.h"

class ListButtonView: public ButtonManager
{
public:
	ListButtonView(TftDisplay *tft, Position position) :
			ButtonManager(tft)
	{
		m_position.x = position.x;
		m_position.y = position.y;
		m_forceDraw = true;
	}
	;
	virtual ~ListButtonView();
	virtual void draw();
	void setForceDraw(bool);
	void addElement(String);
	virtual void selectElementByString(String);
protected:
	bool m_forceDraw;
};

#endif /* LISTBUTTONVIEW_H_ */
