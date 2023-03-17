#include "TempESensor.h"

TempESensor::TempESensor(int pin) :
		TempHum(pin)
{
	this->setMaxValue(100);
	this->setName("Temp E");
	this->setStatus(!isnan(m_dht.readTemperature()));
}

void TempESensor::query()
{
	float t = m_dht.readTemperature();
	m_dht.readHumidity();

	this->setStatus(!isnan(t));
	this->setQueryValue(t);
}
