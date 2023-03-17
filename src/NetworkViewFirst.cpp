#include "NetworkViewFirst.h"
#include <algorithm>

NetworkViewFirst::~NetworkViewFirst()
{
}

void NetworkViewFirst::init()
{
	m_networksList = new ListButtonView(m_tft, Position{ TFTWIDTH / 2,  10});
	updateListView(m_networksList);
	addView(m_networksList);

	m_loadingText = new TextView(m_tft);
	m_loadingText->setPosition(TFTWIDTH / 2,  TFTHEIGHT / 2);
	m_loadingText->setText("Loading...");
	m_loadingText->expandFrameForText();
	m_loadingText->setPosition(m_loadingText->getPosition().x - (m_loadingText->getFrame().getW() / 2), m_loadingText->getPosition().y - (m_loadingText->getFrame().getH() / 2));
	m_loadingText->expandFrameForText();
	m_loadingText->setFrameColor(BLACK);
}

void NetworkViewFirst::draw(){
	constexpr unsigned int refresh_rate_ms = 15000;
	static unsigned int last_time_ms = millis();
	auto time_passed_ms = millis() - last_time_ms;
	if(time_passed_ms >= refresh_rate_ms){
		m_tft->clearScreen();
		m_loadingText->draw();
		updateListView(m_networksList);
		m_windowManager->setDirty(true);
		last_time_ms = millis();
		return;
	}
	String time_passed_ms_str(time_passed_ms / 1000);
	m_tft->text(time_passed_ms_str, TFTWIDTH - (time_passed_ms_str.length() * TEXT_WIDTH) - 5, 2, ORANGE);
	Window::draw();
}

void NetworkViewFirst::updateListView(ListButtonView *listView){
	listView->kickAllElements();

	auto allNetworks = m_networkDevice->getAllNetworks();
	std::sort(allNetworks.begin(), allNetworks.end(),
	    [](const Network &a, const Network &b) -> bool
	{
	    return a.rssi > b.rssi;
	});
	for (auto &network : allNetworks) {
//		Serial.print(network.ssid);
//		Serial.print(": ");
//		Serial.println(network.rssi);
		listView->addElement(network.ssid);
	}

	auto allListElements = listView->getAllElements();
	for(unsigned int i = 0; i < allListElements.size(); i++){
		auto list_elem = allListElements[i];
		constexpr auto max_letter_count = (static_cast<int>((TFTWIDTH - FRAME_MARGIN - 50) / TEXT_WIDTH));

		if(list_elem->getText().length() > max_letter_count){
			String new_text = list_elem->getText();
			String three_dots = "...";
			new_text.remove(max_letter_count - three_dots.length());
			new_text += three_dots;
			list_elem->setText(new_text);
			list_elem->expandFrameForText();
		}
		list_elem->setPosition(list_elem->getPosition().x - (list_elem->getFrame().getW() / 2), list_elem->getPosition().y);
		list_elem->expandFrameForText();
	}
}

void NetworkViewFirst::up()
{
	m_networksList->up();
}

void NetworkViewFirst::down()
{
	m_networksList->down();
}

void NetworkViewFirst::left()
{
	m_windowManager->setCurrentView("ST1");
}

void NetworkViewFirst::specialButton()
{
	m_selectedNetworkName = m_networksList->getSelectedElement()->getText();
	m_windowManager->setCurrentView("N2");
}

void NetworkViewFirst::beforeEntrance()
{
	Window::beforeEntrance();
	m_networksList->setForceDraw(true);
	String name = MEEPROM::instance().read("Name");
	if (name != "") {
		m_networksList->selectElementByString(name);
	}
}

String NetworkViewFirst::getSelectedNetworkName()
{
	return m_selectedNetworkName;
}

NetworkDevice *NetworkViewFirst::getNetworkDevice()
{
	return m_networkDevice;
}
