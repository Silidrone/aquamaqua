#include "PinData.h"

PinData::PinData(uint8_t pin, PinType pinType, int s_range, int e_range)
{
	setPin(pin, pinType, s_range, e_range);
}

void PinData::setPin(uint8_t pin, PinType pinType, int s_range, int e_range)
{
	m_pin = pin;
	m_pinType = pinType;
	m_range.s_range = s_range;
	m_range.e_range = e_range;
}

Range PinData::getRange(){
	return m_range;
}

unsigned int PinData::getPin()
{
	return m_pin;
}

PinType PinData::getPinType()
{
	return m_pinType;
}

int PinData::getLastValue()
{
	return m_lastValue;
}

int PinData::read()
{
	if (m_currentValue) {
		m_lastValue = m_currentValue;
	}
	if (m_pinType == PinType::ANALOG) {
		m_currentValue = analogRead(m_pin);
	} else if (m_pinType == PinType::DIGITAL) {
		m_currentValue = digitalRead(m_pin);
	}

	return m_currentValue;
}
