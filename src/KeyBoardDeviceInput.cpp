#include "KeyBoardDeviceInput.h"

void KeyBoardDeviceInput::initialize()
{
	m_buttons.push_back(PinData(A0, PinType::ANALOG, 40, 60)); /* UP */
	m_buttons.push_back(PinData(A0, PinType::ANALOG, 90, 110)); /* DOWN */
	m_buttons.push_back(PinData(A0, PinType::ANALOG, 10, 30)); /* LEFT */
	m_buttons.push_back(PinData(A0, PinType::ANALOG, 170, 200)); /* RIGHT */
	m_buttons.push_back(PinData(A0, PinType::ANALOG, 330, 400)); /* SPECIAL */
}

PinData* KeyBoardDeviceInput::getUp()
{
	return &(m_buttons[0]);
}

PinData* KeyBoardDeviceInput::getDown()
{
	return &(m_buttons[1]);
}

PinData* KeyBoardDeviceInput::getLeft()
{
	return &(m_buttons[2]);
}

PinData* KeyBoardDeviceInput::getRight()
{
	return &(m_buttons[3]);
}

PinData* KeyBoardDeviceInput::getSpecial()
{
	return &(m_buttons[4]);
}

int KeyBoardDeviceInput::getButtonsSize(){
	return m_buttons.size();
}
 
