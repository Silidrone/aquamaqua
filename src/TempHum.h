#ifndef TEMPHUM_H_
#define TEMPHUM_H_

#include <DHT.h>
#include "Sensor.h"

#define DHTTYPE DHT21   // DHT 21 (AM2301)

class TempHum : public Sensor
{
public:
	TempHum(int pin) :
			Sensor(), m_wire(pin), m_dht(m_wire, DHTTYPE, 15)
	{
		m_dht.begin();
	}
protected:
	int m_wire;
	DHT m_dht;
};

#endif
