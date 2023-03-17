#ifndef VIEWDETAILGRAPH_H_
#define VIEWDETAILGRAPH_H_

#include "Window.h"
#include "Sensor.h"
#include "ViewNumeric.h"
#include "ViewGraph.h"

class ViewDetailGraph: public Window
{
public:
	ViewDetailGraph(TftDisplay *tft, Sensor *s, WindowManager *windowManager) :
			Window(tft, windowManager)
	{
		parseSensor(s);
		m_current_view = m_views.begin();
	}
	virtual ~ViewDetailGraph();
	void setSensor(Sensor *);
	void setSensorIndex(unsigned int);
protected:
	ViewNumeric *numView;
	ViewGraph *graphView;
	static unsigned int m_sensorIndex;
	void parseSensor(Sensor* s);
	void addScaledView(ViewBase* view, int index);
	void down(), right(), left();
	void beforeEntrance();
private:
	void setSensorState(unsigned int index);
};

#endif /* VIEWDETAILGRAPH_H_ */
