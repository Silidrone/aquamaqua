#include "HelperFunctions.h"

HelperFunctions &HelperFunctions::instance()
{
	static HelperFunctions singleton;
	return singleton;
}

String HelperFunctions::convertIntToString(int x)
{
	if (x < 0)
		return String("-") + convertIntToString(-x);
	if (x < 10)
		return String(1, x + '0');
	return convertIntToString(x / 10) + convertIntToString(x % 10);
}

String HelperFunctions::withoutWhiteSpaces(String s){
	for(int i = 0; i < s.length(); i++){
		if(isspace(s.charAt(i))){
			s.remove(i, 1);
		}
	}
	return s;
}
