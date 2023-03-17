#ifndef _WATERLEVELSENSOR_h
#define _WATERLEVELSENSOR_h
#include "Sensor.h"
#include "TftDisplay.h"

class WaterLevelSensor: public Sensor
{
public:
	WaterLevelSensor(int analogPin);
	void query();
protected:
	uint8_t m_wire;
};

#endif

