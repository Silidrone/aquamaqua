#ifndef _TEMPESENSOR_h
#define _TEMPESENSOR_h

#include "TempHum.h"

class TempESensor: public TempHum
{
public:
	TempESensor(int);
	virtual void query();
};

#endif
