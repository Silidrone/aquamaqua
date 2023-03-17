#include "ViewGraph.h"

ViewGraph::~ViewGraph()
{
	delete m_visualData;
}

void ViewGraph::setFrame(int left, int top, int right, int bottom)
{
	ViewBase::setFrame(left, top, right, bottom);
	m_visualData->setFrame(m_frame);
}

void ViewGraph::init()
{
	m_visualData = new VisualData(m_tft);
	int height = 3 * TEXT_HEIGHT + FRAME_MARGIN;
	int width = 10 * TEXT_WIDTH + FRAME_MARGIN;
	setFrame(0, 0, width, height);
}

void ViewGraph::draw()
{
	m_visualData->setForceDraw(m_forceDraw);
	setFrameColor(GREEN);
	drawFrame();
	m_visualData->setMaxValue(m_sensor->getMaxValue());
	m_visualData->setValueWidth(m_sensor->getHistorySize());
	m_visualData->drawCompleteGraphic(m_sensor->getDataHistory(), RED);
	m_forceDraw = false;
}

void ViewGraph::setForceDraw(bool b)
{
	m_forceDraw = b;
}

bool ViewGraph::getForceDraw()
{
	return m_forceDraw;
}
