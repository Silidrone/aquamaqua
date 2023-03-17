#ifndef RELAYVIEW_H_
#define RELAYVIEW_H_

#include "Window.h"
#include "ListRelayButtonView.h"
#include <vector>

class RelayView: public Window
{
public:
	RelayView(TftDisplay *, WindowManager *, std::vector<String> = {});
	virtual void up();
	virtual void down();
	virtual void right();
	virtual void left();
	virtual void specialButton();
protected:
	ListRelayButtonView *m_list_relay_button_view;
};

#endif /* RELAYVIEW_H_ */
