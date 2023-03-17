#ifndef _SENSORCONTROLLER_H
#define _SENSORCONTROLLER_H

#include <vector>

#include "TftDisplay.h"
#include "Temp2Sensor.h"
#include "TempESensor.h"
#include "TempSensor.h"
#include "WaterLevelSensor.h"
#include "HumSensor.h"

class SensorController
{
public:
	~SensorController();
	void initialize();
	void update();
	void checkAllSensors();
	void setDirty();
	std::vector<Sensor *> getSensors();
	Sensor* getSensor(int);
	int getSensorCount();
protected:
	std::vector<Sensor *> m_sensors;
};

#endif
