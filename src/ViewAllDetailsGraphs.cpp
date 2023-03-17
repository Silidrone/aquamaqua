#include "ViewAllDetailsGraphs.h"
#include "ViewNumeric.h"

ViewAllDetailsGraphs::~ViewAllDetailsGraphs()
{
	// TODO Auto-generated destructor stub
}

void ViewAllDetailsGraphs::parseSensors(SensorController* sc)
{
	for (int i = 0; i < sc->getSensorCount(); i++) {
		ViewNumeric *numView = new ViewNumeric(sc->getSensor(i), m_tft);
		numView->setTextSize(1);
		addScaledView(numView, i*2);
		ViewGraph *graphView = new ViewGraph(sc->getSensor(i), m_tft);
		addScaledView(graphView, i*2+1);
		m_graphViews.push_back(graphView);
	}
}

void ViewAllDetailsGraphs::addScaledView(ViewBase* view, int index)
{
	int height = 3 * TEXT_HEIGHT + FRAME_MARGIN;
	int width = 10 * TEXT_WIDTH + FRAME_MARGIN;
	view->setFrame((index % 2) * (width), height * (index / 2), (index % 2) * (width) + width, height * (1 + index / 2));
	ViewComposite::addView(view);
}

void ViewAllDetailsGraphs::beforeEntrance(){
	Window::beforeEntrance();
	for(auto& graphView : m_graphViews){
		graphView->setForceDraw(true);
	}
}
