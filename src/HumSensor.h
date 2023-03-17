#ifndef _HUMSENSOR_h
#define _HUMSENSOR_h

#include "TempHum.h"

class HumSensor: public TempHum
{
public:
	HumSensor(int);
	virtual void query();
};

#endif

