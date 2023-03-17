#include "RelayView.h"

RelayView::RelayView(TftDisplay *tft, WindowManager *windowManager, std::vector<String> names) :
		Window(tft, windowManager)
{
	m_list_relay_button_view = new ListRelayButtonView(tft, Position{30, 3});
	for (auto &name : names) {
		m_list_relay_button_view->addElement(name, false);
	}
	addView(m_list_relay_button_view);
}

void RelayView::up(){
	m_list_relay_button_view->up();
}

void RelayView::down(){
	m_list_relay_button_view->down();
}

void RelayView::right(){
	m_windowManager->setCurrentView("N1");
}

void RelayView::left(){
	m_windowManager->setCurrentView("ST1");
}

void RelayView::specialButton(){
	// Serial.println(((RelayButton*)(m_list_relay_button_view->getSelectedElement()))->getName());
}
