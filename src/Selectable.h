#ifndef SELECTABLE_H_
#define SELECTABLE_H_

#include "ViewBase.h"

class Selectable
{
public:
	Selectable()
	{
		m_selected = false;
	}
	;
	virtual ~Selectable() = 0;
	virtual void select();
	virtual void deselect();
	virtual bool isSelected();
protected:
	bool m_selected;
};

#endif /* SELECTABLE_H_ */
