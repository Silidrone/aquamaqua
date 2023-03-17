#ifndef _SENSOR_h
#define _SENSOR_h

#include "WString.h"
#include "TftDisplay.h"
#include "LinkedList.h"

class Sensor
{

public:
	Sensor();
	virtual ~Sensor();

	virtual void query() = 0;

	void setName(String), setMaxValue(int), setStatus(bool), setHistorySize(int);
	void addValue(int);
	int getMaxValue(), getQueriedValue(), getHistorySize();
	bool getStatus();
	bool statusChanged();
	String getName(void);
	LinkedList *getDataHistory(void);
protected:
	String m_name;
	int m_queriedValue, m_maxValue, m_historySize;
	bool m_status, m_statusChanged;
	LinkedList *m_dataHistory;
	void setQueryValue(int);
private:
	int m_previous_status;
};

#endif
