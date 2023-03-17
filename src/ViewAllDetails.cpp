#include "ViewAllDetails.h"

void ViewAllDetails::parseSensors(SensorController *sc)
{
	int height = 3 * TEXT_HEIGHT + FRAME_MARGIN;
	int width = 10 * TEXT_WIDTH + FRAME_MARGIN;
	for (int i = 0; i < sc->getSensorCount(); i++) {
		ViewNumeric *numView = new ViewNumeric(sc->getSensor(i), m_tft);
		numView->setFrame((i % 2) * (width), height * (i / 2), (i % 2) * (width) + width, height * (1 + i / 2));
		ViewComposite::addView(numView);
	}
}

void ViewAllDetails::up()
{
	m_windowManager->setCurrentView("DG1");
}
void ViewAllDetails::down()
{
	m_windowManager->setCurrentView("ST1");
}
