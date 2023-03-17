#include "ViewComposite.h"

void ViewComposite::draw()
{
	if (m_views.empty()) {
		return;
	}
	(*m_current_view)->draw();
	m_current_view++;
	if (m_current_view == m_views.end()) {
		m_current_view = m_views.begin();
	}
}

ViewComposite::~ViewComposite(){
	for(auto &view : m_views){
		delete view;
	}
}

void ViewComposite::addView(ViewBase* v)
{
	m_views.push_back(v);
	m_current_view = m_views.begin();
}

void ViewComposite::kickView(unsigned int index)
{
	delete (*(m_views.begin() + index));
	m_views.erase(m_views.begin() + index);
}

void ViewComposite::kickAllViews()
{
	auto size = m_views.size();
	for (unsigned int i = 0; i < size; i++) {
		kickView(0);
	}
}
