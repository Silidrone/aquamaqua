#include "WaterLevelSensor.h"

WaterLevelSensor::WaterLevelSensor(int analogPin) :
		Sensor(), m_wire(analogPin)
{
	this->setMaxValue(200);
	this->setName("WL1");
	this->setStatus(true);
}
;

void WaterLevelSensor::query()
{
	int wlv = analogRead(m_wire);
	this->setQueryValue(wlv);
}
