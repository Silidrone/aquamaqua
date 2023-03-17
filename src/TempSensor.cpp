#include "TempSensor.h"

TempSensor::TempSensor(int pin) :
		Sensor(), m_wire(pin), m_oneWire(m_wire), m_sensor(&m_oneWire), m_resolution(12)
{
	DeviceAddress tempDeviceAddress;
	m_sensor.begin();
	if (!m_sensor.getAddress(tempDeviceAddress, 0)) {
		this->setStatus(false);
	} else {
		this->setStatus(true);
	}
	m_sensor.setResolution(tempDeviceAddress, m_resolution);
	m_sensor.setWaitForConversion(false);
	m_sensor.requestTemperatures();
	//Serial.print("Parasite power is: "); 
	//if (m_sensor.isParasitePowerMode()) Serial.println("ON");
	// else Serial.println("OFF");
	this->setMaxValue(40);
	this->setName("Temp 1");
}
;

void TempSensor::query()
{
	float t = m_sensor.getTempCByIndex(0);
	this->setQueryValue(t);
	this->setStatus(true);
}

