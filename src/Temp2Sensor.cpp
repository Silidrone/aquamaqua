#include "Temp2Sensor.h"

Temp2Sensor::Temp2Sensor(int pin) :
		Sensor(), m_wire(pin), m_oneWire(m_wire), m_sensor(&m_oneWire), m_resolution(12)
{
	DeviceAddress tempDeviceAddress;
	m_sensor.begin();
	if (!m_sensor.getAddress(tempDeviceAddress, 0)) {
		this->setStatus(false);
	} else{
		this->setStatus(true);
	}
	m_sensor.setResolution(tempDeviceAddress, m_resolution);
	m_sensor.setWaitForConversion(false);
	m_sensor.requestTemperatures();

	this->setMaxValue(40);
	this->setName("Temp 2");
}


void Temp2Sensor::query()
{
	float t = m_sensor.getTempCByIndex(0);
	this->setQueryValue(t);

	m_sensor.requestTemperatures();
}
