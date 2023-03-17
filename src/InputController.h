#ifndef _INPUTCONTROLLER_h
#define _INPUTCONTROLLER_h

#include <Arduino.h>
#include "PinData.h"

#define MAXLINKAGES 100

typedef void (*vfp)(); //vfp : void function pointer

struct Linkage
{
	PinData* pinData;
	vfp func;
};

class InputController
{
public:
	void initialize();
	void checkInputs();
	void addLinkage(PinData*, vfp);
	void setBeforeFunc(vfp func) { m_beforeFunc = func; };
	void setAfterFunc(vfp func) { m_afterFunc = func; };
protected:
	void callFunctionPack(vfp);
	Linkage m_linkages[MAXLINKAGES];
	vfp m_beforeFunc, m_afterFunc;
	int m_linkp;
};

#endif
