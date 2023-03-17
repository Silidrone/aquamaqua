#include "ListButtonView.h"

ListButtonView::~ListButtonView()
{
}

void ListButtonView::draw()
{
	if (m_forceDraw) {
		for (auto& view : m_views) {
			view->draw();
		}
		m_forceDraw = false;
	}
	if (m_lastSelectedElement != m_selectedElement) {
		m_selectedElement->eraseFrame();
		m_selectedElement->drawFrame();
		if (m_lastSelectedElement != nullptr) {
			m_lastSelectedElement->eraseFrame();
			m_lastSelectedElement->drawFrame();
		}
		m_lastSelectedElement = m_selectedElement;
	}
}

void ListButtonView::setForceDraw(bool b)
{
	m_forceDraw = b;
}

void ListButtonView::addElement(String text)
{
	static unsigned int list_element_height = ButtonView::getTextHeight();
	constexpr unsigned int element_gap = 2;

	int elementY1 = m_position.y + (m_views.size() * (list_element_height + element_gap));
	if(elementY1 + list_element_height + element_gap >= TFTHEIGHT){
		return;
	}

	ButtonView *listElementView = new ButtonView(m_tft);
	addView(listElementView);
	listElementView->setPosition(m_position.x, elementY1);
	listElementView->setText(text);
	listElementView->expandFrameForText();
	if (m_views.size() == 1) {
		selectElement(listElementView);
	}
}

void ListButtonView::selectElementByString(String name)
{
	int index = 0;
	for (auto& view : m_views) {
		ButtonView *listElementView = (ButtonView*) view;
		if (listElementView->getText() == name) {
			selectElement(listElementView);
			m_index = index;
		}
		index++;
	}
}
