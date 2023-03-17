#ifndef BUTTONMANAGER_H_
#define BUTTONMANAGER_H_

#include "ViewComposite.h"
#include "ButtonView.h"
#include <vector>

class ButtonManager : public ViewComposite
{
public:
	ButtonManager(TftDisplay *);
	virtual ~ButtonManager() {};
	virtual void up();
	virtual void down();

	ButtonView *getSelectedElement();
	ButtonView *getElement(unsigned int);
	std::vector<ButtonView *> getAllElements();
	void kickElement(unsigned int);
	void kickAllElements();

	void selectElement(ButtonView*);
protected:
	int m_index;
	ButtonView *m_selectedElement;
	ButtonView *m_lastSelectedElement;
};

#endif /* BUTTONMANAGER_H_ */
