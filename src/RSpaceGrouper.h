#ifndef _RSpaceGrouper_h
#define _RSpaceGrouper_h

#define MAXIMUMBOUNDOBJECTS 10

#include "RSpace.h"

class RSpaceGrouper
{
public:
	RSpaceGrouper();
	~RSpaceGrouper();
	void bound(RSpace*);
	void draw();
	void clear();
	void erase();
	void setTft(TftDisplay*);
	TftDisplay* getTft();
private:
	TftDisplay* m_tft;
	RSpace* m_boundObjects[MAXIMUMBOUNDOBJECTS];
	int m_boundObjectsP;
};

#endif
