#ifndef VIEWALLDETAILSGRAPHS_H_
#define VIEWALLDETAILSGRAPHS_H_

#include "Window.h"
#include "SensorController.h"
#include "ViewGraph.h"
#include <vector>

class ViewAllDetailsGraphs: public Window
{
public:
	ViewAllDetailsGraphs(TftDisplay *tft, SensorController *sc, WindowManager *windowManager) :
		Window(tft, windowManager)
	{
		parseSensors(sc);
		m_current_view=m_views.begin();
	}
	virtual ~ViewAllDetailsGraphs();
protected:
	void up() {
		m_windowManager->setCurrentView("S0");
	};
	void down() {
		m_windowManager->setCurrentView("D1");
	};
	void beforeEntrance();
	void parseSensors(SensorController *sc);
	void addScaledView(ViewBase *, int);
	std::vector<ViewGraph *> m_graphViews;
};

#endif /* VIEWALLDETAILSGRAPHS_H_ */
