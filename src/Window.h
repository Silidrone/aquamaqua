#ifndef WINDOW_H_
#define WINDOW_H_

#include "WindowManager.h"
#include "ViewComposite.h"


class Window: public ViewComposite
{
public:
	Window(TftDisplay *tft, WindowManager* windowManager) :
			ViewComposite(tft)
	{
		m_windowManager = windowManager;
	}
	;

	virtual ~Window() {};
	virtual void up() { };
	virtual void down() { };
	virtual void right() { };
	virtual void left() { };
	virtual void specialButton() { };
	virtual void beforeEntrance() { m_tft->clearScreen(); /*Serial.println("DEFAULT BEFORE ENTRANCE");*/ };
protected:
	WindowManager *m_windowManager;
};

#endif /* WINDOW_H_ */
