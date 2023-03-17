#ifndef VIEWALLDETAILS_H_
#define VIEWALLDETAILS_H_

#include "Window.h"
#include "ViewNumeric.h"
#include "SensorController.h"

class ViewAllDetails: public Window
{
public:
	ViewAllDetails(TftDisplay *tft, SensorController *sc, WindowManager *windowManager) :
		Window(tft, windowManager)
	{
		parseSensors(sc);
		m_current_view = m_views.begin();
	}
protected:
	void parseSensors(SensorController *sc);
	void up(), down();
};

#endif /* VIEWALLDETAILS_H_ */
