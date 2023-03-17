#ifndef PINDATA_H_
#define PINDATA_H_

#include "Arduino.h"

enum class PinType
	: int
	{
		ANALOG, DIGITAL, NONE
};

struct Range
{
	int s_range, e_range;
};

class PinData
{
public:
	PinData(uint8_t pin, PinType pinType, int s_range, int e_range);
	void setPin(uint8_t pin, PinType pinType, int s_range, int e_range);
	unsigned int getPin();
	PinType getPinType();
	Range getRange();
	int read();
	int getLastValue();
protected:
	unsigned int m_pin;
	int m_currentValue, m_lastValue;
	Range m_range;
	PinType m_pinType;
};

#endif /* PINDATA_H_ */
