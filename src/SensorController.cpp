#include "SensorController.h"

void SensorController::initialize()
{
	m_sensors.push_back(new TempSensor(3));
	m_sensors.push_back(new Temp2Sensor(3));
	m_sensors.push_back(new TempESensor(2));
	m_sensors.push_back(new HumSensor(2));
	m_sensors.push_back(new WaterLevelSensor(A0));
	for (unsigned int i = 0; i < m_sensors.size(); i++) {
		m_sensors[i]->setHistorySize(10);
	}
}

SensorController::~SensorController()
{
	for (unsigned int i = 0; i < m_sensors.size(); i++) {
		delete m_sensors[i];
	}
}

void SensorController::update()
{
	checkAllSensors();
}

void SensorController::setDirty()
{
	for (unsigned int i = 0; i < m_sensors.size(); i++) {
		m_sensors[i]->getDataHistory()->setDirty();
	}
}

void SensorController::checkAllSensors()
{
	for (unsigned int i = 0; i < m_sensors.size(); i++) {
		m_sensors[i]->query();
		m_sensors[i]->addValue(m_sensors[i]->getQueriedValue());
	}
}

std::vector<Sensor *> SensorController::getSensors()
{
	return m_sensors;
}

Sensor* SensorController::getSensor(int index)
{
	return m_sensors[index];
}

int SensorController::getSensorCount()
{
	return m_sensors.size();
}
