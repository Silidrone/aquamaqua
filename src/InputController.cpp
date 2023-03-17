#include "InputController.h"

void InputController::initialize()
{
	m_linkp = 0;
	memset(m_linkages, 0, sizeof(m_linkages));
	m_beforeFunc = m_afterFunc = NULL;
}

void InputController::checkInputs()
{
	int currentValue, lastValue;
	int i;

	Linkage* p;
	PinData* pinData;
	Range range;

	currentValue = lastValue = i = range.s_range = range.e_range = 0;
	for (p = m_linkages; i < m_linkp; p++, i++) {
		pinData = p->pinData;
		range = pinData->getRange();
		currentValue = pinData->read();
		lastValue = pinData->getLastValue();

		if (lastValue && abs(currentValue - lastValue) <= abs(range.s_range - range.e_range)) {
 			continue;
		}

		if (pinData->getPinType() == PinType::ANALOG) {
			//Serial.println(currentValue);
			if (currentValue >= range.s_range && currentValue <= range.e_range) {
				callFunctionPack(p->func);
			}
		} else if (pinData->getPinType() == PinType::DIGITAL) {
			if (currentValue) {
				callFunctionPack(p->func);
			}
		}

	}
}

void InputController::callFunctionPack(vfp f)
{
	if (m_beforeFunc != nullptr) {
		m_beforeFunc();
	}
	f();
	if (m_afterFunc != nullptr) {
		m_afterFunc();
	}
}

void InputController::addLinkage(PinData* pinData, vfp func)
{
	if (m_linkp >= MAXLINKAGES - 1) {
		return;
	}

	m_linkages[m_linkp].pinData = pinData;
	m_linkages[m_linkp].func = func;
	m_linkp++;
}
