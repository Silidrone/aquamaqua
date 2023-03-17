#ifndef NETWORKVIEWSECOND_H_
#define NETWORKVIEWSECOND_H_

#include "Window.h"
#include "KeyBoardView.h"
#include "TextView.h"
#include "InputBoxView.h"
#include "NetworkViewFirst.h"
#include "MEEPROM.h"

class NetworkViewSecond: public Window
{
public:
	NetworkViewSecond(TftDisplay *tft, WindowManager *windowManager, NetworkViewFirst *networkViewFirst) :
			Window(tft, windowManager)
	{
		m_networkViewFirst = networkViewFirst;
		m_forceDraw = true;
		init(tft);
	}
	;
	virtual ~NetworkViewSecond();
	virtual void up(), down(), right(), left(), specialButton();
	virtual void draw();
	virtual void beforeEntrance();
	void setForceDraw(bool);
protected:
	KeyBoardView *m_keyBoardView;
	InputBoxView *m_inputBox;
	NetworkViewFirst *m_networkViewFirst;
	TextView *m_loadingText;
	bool m_forceDraw;
private:
	void nextClicked();
	void init(TftDisplay *);
};

#endif /* NETWORKVIEWSECOND_H_ */
