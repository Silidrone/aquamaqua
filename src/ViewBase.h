#ifndef VIEWBASE_H_
#define VIEWBASE_H_

#include "Rectangle.h"
#include "TftDisplay.h"

struct Position{
	int x, y;
};

class ViewBase
{
public:
	ViewBase(TftDisplay *tft);
	//ViewBase(ViewBase&);
	virtual ~ViewBase();
	virtual void draw()=0;
	virtual void setFrame(int, int, int, int);
	virtual void setFrame(Rectangle);
	virtual void setPosition(int, int);
	virtual void setPosition(Position);
	virtual Position getPosition();
	virtual Rectangle getFrame();
	virtual void setFrameColor(unsigned int);
	virtual void drawFrame();
	virtual void eraseFrame();
	virtual void eraseInsideFrame();
protected:
	Rectangle m_frame;
	TftDisplay *m_tft;
	Position m_position;
	unsigned int m_frameColor;
};

#endif /* VIEWBASE_H_ */
