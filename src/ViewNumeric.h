#ifndef VIEWNUMERIC_H_
#define VIEWNUMERIC_H_

#include "ViewSensor.h"

class ViewNumeric: public ViewSensor
{
public:
	ViewNumeric(Sensor *s, TftDisplay *tft) :
			ViewSensor(s, tft), m_textSize(1)
	{
	}
	;
	virtual ~ViewNumeric();
	virtual void draw();
	void setTextSize(int size);
protected:
	int m_textSize;
};

#endif /* VIEWNUMERIC_H_ */
