#ifndef VIEWCOMPOSITE_H_
#define VIEWCOMPOSITE_H_

#include "ViewBase.h"
#include <vector>

class ViewComposite: public ViewBase
{
public:
	ViewComposite(TftDisplay *tft) :
			ViewBase(tft)
	{
	}
	;

	virtual ~ViewComposite();
	/*ViewComposite(const ViewComposite& other) : ViewComposite(other) { //copy ctor
		m_current_view = other.m_current_view;
		std::copy(other.m_views.begin(), other.m_views.end(), m_views.begin());
	};*/
	virtual void draw();
	void addView(ViewBase *);
	void kickView(unsigned int);
	void kickAllViews();
protected:
	std::vector<ViewBase*> m_views;
	std::vector<ViewBase*>::iterator m_current_view;
};

#endif /* VIEWCOMPOSITE_H_ */
