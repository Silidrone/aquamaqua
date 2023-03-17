#ifndef KEYBOARDDEVICEINPUT_H_
#define KEYBOARDDEVICEINPUT_H_

#include <vector>
#include "PinData.h"

class KeyBoardDeviceInput
{
public:
	void initialize();
	PinData* getUp();
	PinData* getDown();
	PinData* getLeft();
	PinData* getRight();
	PinData* getSpecial();
	int getButtonsSize();
protected:
	std::vector<PinData> m_buttons;
};

#endif /* KEYBOARDDEVICEINPUT_H_ */
