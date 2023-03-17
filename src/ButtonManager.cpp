#include "ButtonManager.h"

ButtonManager::ButtonManager(TftDisplay *tft) : ViewComposite(tft){
	m_index = 0;
	m_selectedElement = m_lastSelectedElement = nullptr;
};

void ButtonManager::selectElement(ButtonView *element)
{
	m_lastSelectedElement = m_selectedElement;
	if (m_lastSelectedElement != nullptr) {
		m_lastSelectedElement->deselect();
	}
	m_selectedElement = element;
	m_selectedElement->select();
}

ButtonView *ButtonManager::getElement(unsigned int index){
	if(index >= m_views.size()){
		return nullptr;
	}
	return (ButtonView *) m_views[index];
}

std::vector<ButtonView *> ButtonManager::getAllElements(){
	std::vector<ButtonView *> tmp_v;
	for(auto &view : m_views){
		tmp_v.push_back((ButtonView *) view);
	}
	return tmp_v;
}

ButtonView *ButtonManager::getSelectedElement(){
	return m_selectedElement;
}

void ButtonManager::kickElement(unsigned int index)
{
	if(m_selectedElement == m_views[index]){
		m_selectedElement = nullptr;
	} else if (m_lastSelectedElement == m_views[index]){
		m_lastSelectedElement = nullptr;
	}
	kickView(index);
}

void ButtonManager::kickAllElements(){
	kickAllViews();
	m_lastSelectedElement = m_selectedElement = nullptr;
}

void ButtonManager::up()
{
	if (m_index - 1 < 0) {
		m_index = m_views.size() - 1;
	} else {
		m_index -= 1;
	}
	selectElement((ButtonView*) m_views[m_index]);
}

void ButtonManager::down()
{
	if (m_index + 1 > m_views.size() - 1) {
		m_index = 0;
	} else {
		m_index += 1;
	}
	selectElement((ButtonView*) m_views[m_index]);
}
