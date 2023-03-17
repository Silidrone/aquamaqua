#ifndef NETWORKVIEWFIRST_H_
#define NETWORKVIEWFIRST_H_

#include "ListButtonView.h"
#include "MEEPROM.h"
#include "Window.h"
#include "NetworkDevice.h"

class NetworkViewFirst: public Window
{
public:
	NetworkViewFirst(TftDisplay *tft, WindowManager *windowManager, NetworkDevice *networkDevice) :
			Window(tft, windowManager)
	{
		m_networkDevice = networkDevice;
		m_networksList = nullptr;
		init();
	}
	;
	virtual void draw();
	virtual void updateListView(ListButtonView*);
	virtual void up();
	virtual void down();
	virtual void left();
	virtual void specialButton();
	virtual void beforeEntrance();
	String getSelectedNetworkName();
	virtual ~NetworkViewFirst();
	NetworkDevice *getNetworkDevice();
protected:
	NetworkDevice *m_networkDevice;
	ListButtonView *m_networksList;
	String m_selectedNetworkName;
private:
	TextView *m_loadingText;
	void init();
};

#endif /* NETWORKVIEWFIRST_H_ */
