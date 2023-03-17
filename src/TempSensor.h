#ifndef _TEMPSENSOR_h
#define _TEMPSENSOR_h
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Sensor.h"

class TempSensor: public Sensor
{
public:
	TempSensor(int pin);
	void query();
protected:
	int m_wire;
	OneWire m_oneWire;
	DallasTemperature m_sensor;
	int m_resolution;
};
#endif // !__TEMP_SENSOR__
