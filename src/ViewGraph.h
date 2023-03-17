#ifndef VIEWGRAPH_H_
#define VIEWGRAPH_H_

#include "ViewSensor.h"
#include "VisualData.h"

class ViewGraph: public ViewSensor
{
public:
	ViewGraph(Sensor *s, TftDisplay *tft) :
			ViewSensor(s, tft)
	{
		init();
	}
	;
	virtual ~ViewGraph();
	virtual void draw();
	virtual void setFrame(int left, int top, int right, int bottom);
	void setForceDraw(bool);
	bool getForceDraw();
protected:
	VisualData *m_visualData;
	bool m_forceDraw;
	void init();
};

#endif /* VIEWGRAPH_H_ */
