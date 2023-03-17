#ifndef VIEWSENSOR_H_
#define VIEWSENSOR_H_

#include "ViewBase.h"
#include "Sensor.h"

class ViewSensor: public ViewBase
{
public:
	ViewSensor(Sensor *s, TftDisplay *tft) :
			ViewBase(tft)
	{
		m_sensor = s;
	}
	;
	virtual ~ViewSensor();
	void setSensor(Sensor *);
protected:
	Sensor *m_sensor;
};

#endif /* VIEWSENSOR_H_ */
