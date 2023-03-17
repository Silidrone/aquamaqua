#include "Status.h"

Status::~Status()
{
	// TODO Auto-generated destructor stub
}

void Status::draw()
{
	auto&& sensors = m_sensorController->getSensors();

	Position sensorDescLinePos = drawLabel("SENSORS STATUS", 5, 10);

	for (unsigned int i = 0; i < sensors.size(); i++) {
		if (sensors[i]->statusChanged() || m_forceDraw) {
			drawStatus(sensors[i]->getName(), sensors[i]->getStatus(), sensorDescLinePos.x + 5, sensorDescLinePos.y + 5 + (i * 10));
		}
	}

	Position networkDescLinePos = drawLabel("NETWORK STATUS", 5, sensorDescLinePos.y + 5 + (sensors.size() * 10));
	bool networkStatus = m_networkDevice->getStatus();
	String statusText((networkStatus ? "OK" : "NOT OK"));
	m_tft->text("Status: " + statusText, networkDescLinePos.x + 5, networkDescLinePos.y + 5, (networkStatus ? GREEN : RED));
	String rssiQualityText(2 * (m_networkDevice->getCurrentNetwork().rssi + MAXIMUM_RSSI_VALUE));
	m_tft->text("RSSI Quality: " + rssiQualityText, networkDescLinePos.x + 5, networkDescLinePos.y + 5 + TEXT_HEIGHT + 5, CYAN);

	m_networkTestButton->setPosition(networkDescLinePos.x + 5, networkDescLinePos.y + 5 + (TEXT_HEIGHT * 3) + 5 + 5);
	m_networkTestButton->setText("TEST NETWORK");
	m_networkTestButton->expandFrameForText();
	m_networkTestButton->draw();

	this->setForceDraw(false);
}

void Status::drawStatus(String name, int status, int x, int y)
{
	String statusText;
	unsigned int color;
	if (status) {
		color = GREEN;
		statusText = "OK";
	} else {
		color = RED;
		statusText = "NOT OK";
	}

	int deletionX1 = x + (name.length() + 2) * TEXT_WIDTH;
	int deletionY1 = y - TEXT_HEIGHT / 2 + 3;
	int deletionX2 = TFTWIDTH;
	int deletionY2 = y + TEXT_HEIGHT / 2 + 3;
	Rectangle deletionRect(deletionX1, deletionY1, deletionX2, deletionY2);

	m_tft->fillRect(deletionRect, BLACK);
	m_tft->text(name + ": " + statusText, x, y, color);
}

void Status::beforeEntrance()
{
	Window::beforeEntrance();
	this->setForceDraw(true);
}

void Status::specialButton(){
	m_networkDevice->invokeGetURL("am.lappasoft.com", "/u/debug=true");
}

void Status::up()
{
	m_windowManager->setCurrentView("D1");
}

void Status::down()
{
	m_windowManager->setCurrentView("R1");
}

void Status::right()
{
	m_windowManager->setCurrentView("N1");
}