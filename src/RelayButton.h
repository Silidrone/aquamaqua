#ifndef RELAYBUTTON_H_
#define RELAYBUTTON_H_

#include "ViewBase.h"
#include "Selectable.h"
#include "ButtonView.h"

class RelayButton: public ButtonView
{
public:
	RelayButton(TftDisplay *);
	static int getTextHeight();
	void setName(String);
	String getName();
	void setStatus(bool);
	bool getStatus();
	void toggleStatus();

	virtual void draw();
	virtual Rectangle calculateFrame();
	virtual void expandFrameForText();
protected:
	String m_nameDesc, m_statusDesc;
	String m_name;
	bool m_status;
private:
	int getTextWidth();
};

#endif /* RELAYBUTTON_H_ */
