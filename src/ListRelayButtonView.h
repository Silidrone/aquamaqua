#ifndef LISTRELAYBUTTONVIEW_H_
#define LISTRELAYBUTTONVIEW_H_

#include "ListButtonView.h"
#include "RelayButton.h"

class ListRelayButtonView: public ListButtonView
{
public:
	ListRelayButtonView(TftDisplay *tft, Position position) :
			ListButtonView(tft, position)
	{
	}
	;
	virtual ~ListRelayButtonView();
	void addElement(String, bool);
	virtual void selectElementByString(String);
};

#endif /* LISTRELAYBUTTONVIEW_H_ */
