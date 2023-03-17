#include "ViewDetailGraph.h"

unsigned int ViewDetailGraph::m_sensorIndex = 0;

ViewDetailGraph::~ViewDetailGraph()
{

}

void ViewDetailGraph::parseSensor(Sensor *s)
{
	numView = new ViewNumeric(s, m_tft);
	numView->setTextSize(2);
	addScaledView(numView, 1);
	graphView = new ViewGraph(s, m_tft);
	addScaledView(graphView, 2);
}

void ViewDetailGraph::addScaledView(ViewBase* view, int index)
{
	int height = 3 * TEXT_HEIGHT * 2 + FRAME_MARGIN;
	int width = 10 * TEXT_WIDTH + FRAME_MARGIN;
	view->setFrame(0, height * (index / 2), width * 2, height * (1 + index / 2));
	ViewComposite::addView(view);
}

void ViewDetailGraph::setSensor(Sensor *s)
{
	numView->setSensor(s);
	graphView->setSensor(s);
}

void ViewDetailGraph::down()
{
	m_windowManager->setCurrentView("DG1");
	m_sensorIndex = 0;
}

void ViewDetailGraph::left()
{
	if (m_sensorIndex > 0) {
		m_sensorIndex--;
	} else {
		m_sensorIndex = m_windowManager->getSensorCount() - 1;
	}
	setSensorState(m_sensorIndex);
}

void ViewDetailGraph::right()
{
	if (m_sensorIndex < m_windowManager->getSensorCount() - 1) {
		m_sensorIndex++;
	} else {
		m_sensorIndex = 0;
	}
	setSensorState(m_sensorIndex);
}

void ViewDetailGraph::setSensorState(unsigned int index)
{
	String name = "S";
	name += index;
//	Serial.print("SETTING: ");
//	Serial.println(name);
	m_windowManager->setCurrentView(name);
}

void ViewDetailGraph::beforeEntrance()
{
	Window::beforeEntrance();
	graphView->setForceDraw(true);
}
