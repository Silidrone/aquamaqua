#include "Sensor.h"

Sensor::Sensor()
{
	m_dataHistory = new LinkedList();
	m_name = "DEFAULT";
	m_queriedValue = m_maxValue = m_status = m_historySize = m_statusChanged = 0;
	m_previous_status = 2;
}

Sensor::~Sensor()
{
	delete m_dataHistory;
}

void Sensor::setName(String name)
{
	m_name = name;
}

String Sensor::getName(void)
{
	return m_name;
}

void Sensor::addValue(int value)
{
	/* Remove last node if the node count is more than historySize */
	if (m_dataHistory->getCount() == m_historySize) {
		m_dataHistory->removeNode(m_dataHistory->end->prev); // Remove last node
	}
	m_dataHistory->addNodeAfter(m_dataHistory->start, value);
}

void Sensor::setQueryValue(int value)
{
	m_queriedValue = value;
}

int Sensor::getQueriedValue()
{
	return m_queriedValue;
}

void Sensor::setMaxValue(int maxValue)
{
	m_maxValue = maxValue;
}

int Sensor::getMaxValue()
{
	return m_maxValue;
}

void Sensor::setStatus(bool status)
{
	if(m_previous_status == 2 || m_previous_status != status){
		m_status = status;
		m_statusChanged = true;
	}
	m_previous_status = status;
}

bool Sensor::getStatus()
{
	return m_status;
}

bool Sensor::statusChanged(){
	bool statusChanged = m_statusChanged;
	m_statusChanged = false;
	return statusChanged;
}

void Sensor::setHistorySize(int dhs)
{
	m_historySize = dhs;
}

int Sensor::getHistorySize()
{
	return m_historySize;
}

LinkedList *Sensor::getDataHistory(void)
{
	return m_dataHistory;
}
