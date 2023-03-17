#ifndef STATUS_H_
#define STATUS_H_

#include "Window.h"
#include "SensorController.h"
#include "NetworkDevice.h"
#include "ButtonView.h"

class Status: public Window
{
	struct Position
	{
		int x, y;
	};
public:
	Status(TftDisplay *tft, SensorController *sc, WindowManager* windowManager, NetworkDevice* networkDevice) :
			Window(tft, windowManager)
	{
		m_sensorController = sc;
		m_networkDevice = networkDevice;
		m_forceDraw = false;
		m_networkTestButton = new ButtonView(m_tft);
	}
	;
	virtual ~Status();

	virtual void draw();
	virtual void up();
	virtual void down();
	virtual void right();
	virtual void specialButton();
	virtual void beforeEntrance();

	void setForceDraw(bool b)
	{
		m_forceDraw = b;
	}
	;bool getForceDraw()
	{
		return m_forceDraw;
	}
	;
protected:
	SensorController *m_sensorController;
	NetworkDevice *m_networkDevice;
	ButtonView *m_networkTestButton;
	bool m_forceDraw;
private:
	Position drawLabel(String text, int x1, int y1)
	{
		int lineX1 = x1 - 2;
		int lineY1 = y1 + TEXT_HEIGHT + 2;
		int lineX2 = x1 + text.length() * TEXT_WIDTH + 2;
		int lineY2 = lineY1;

		m_tft->text(text, x1, y1, BLUE);
		m_tft->myDrawLine(lineX1, lineY1, lineX2, lineY2, BLUE);
		Position endPos { lineX1, lineY1 };
		return endPos;
	}
	void drawStatus(String, int, int, int);
};

#endif /* STATUS_H_ */
