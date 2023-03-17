#include "RSpaceGrouper.h"

RSpaceGrouper::RSpaceGrouper()
{
	m_boundObjectsP = 0;
}

RSpaceGrouper::~RSpaceGrouper()
{

}

void RSpaceGrouper::bound(RSpace* object)
{
	if (m_boundObjectsP < MAXIMUMBOUNDOBJECTS) {
		m_boundObjects[m_boundObjectsP++] = object;
	}
}

void RSpaceGrouper::draw()
{
	for (int i = 0; i < m_boundObjectsP; i++) {
		m_boundObjects[i]->draw();
	}

}

void RSpaceGrouper::clear()
{
	for (int i = 0; i < m_boundObjectsP; i++) {
		m_boundObjects[i]->clearInside();
	}
}

void RSpaceGrouper::erase()
{
	for (int i = 0; i < m_boundObjectsP; i++) {
		m_boundObjects[i]->clearOutside();
	}
}

void RSpaceGrouper::setTft(TftDisplay* tft)
{
	m_tft = tft;
}

TftDisplay* RSpaceGrouper::getTft()
{
	return m_tft;
}
