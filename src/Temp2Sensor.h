#ifndef _TEMP2SENSOR_h
#define _TEMP2SENSOR_h
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Sensor.h"

class Temp2Sensor: public Sensor
{
public:
	Temp2Sensor(int pin);
	void query();
protected:
	int m_wire;
	OneWire m_oneWire;
	DallasTemperature m_sensor;
	int m_resolution;
};
#endif // !__TEMP_SENSOR__
