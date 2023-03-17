#include "ListRelayButtonView.h"

ListRelayButtonView::~ListRelayButtonView()
{
}

void ListRelayButtonView::addElement(String name, bool status)
{
	static unsigned int list_element_height = RelayButton::getTextHeight();
	constexpr unsigned int element_gap = 2;

	int elementY1 = m_position.y + (m_views.size() * (list_element_height + element_gap));
	if(elementY1 + list_element_height + element_gap >= TFTHEIGHT){
		return;
	}

	RelayButton *listElementView = new RelayButton(m_tft);
	addView(listElementView);
	listElementView->setPosition(m_position.x, elementY1);
	listElementView->setName(name);
	listElementView->setStatus(status);
	listElementView->expandFrameForText();
	if (m_views.size() == 1) {
		selectElement(listElementView);
	}
}

void ListRelayButtonView::selectElementByString(String name)
{
	int index = 0;
	for (auto& view : m_views) {
		RelayButton *listElementView = (RelayButton*) view;
		if (listElementView->getName() == name) {
			selectElement(listElementView);
			m_index = index;
		}
		index++;
	}
}
