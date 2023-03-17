#include "HumSensor.h"

HumSensor::HumSensor(int pin) :
		TempHum(pin)
{
	this->setMaxValue(100);
	this->setName("Humidity");
	this->setStatus(!isnan(m_dht.readHumidity()));
}

void HumSensor::query()
{
	//m_dht.readTemperature(); //bug in the DHT library
	//float h = m_dht.readHumidity();
	float h = random(0, this->getMaxValue());


	this->setStatus(!isnan(h));
	this->setQueryValue(h);
}
