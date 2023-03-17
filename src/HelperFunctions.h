#ifndef HELPERFUNCTIONS_H_
#define HELPERFUNCTIONS_H_

#include "Arduino.h"

class HelperFunctions
{
public:
	static HelperFunctions &instance();
	String convertIntToString(int);
	String withoutWhiteSpaces(String);
};

#endif
