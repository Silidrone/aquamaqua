#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Arduino.h"
#include <vector>

class Rectangle
{
public:
	Rectangle();
	Rectangle(int, int, int, int);
	void setCoordinates(int, int, int, int), setStartCoordinates(int, int), setEndCoordinates(int, int);
	int getX1() const, getY1() const, getX2() const, getY2() const, getW() const, getH() const;
	Rectangle operator+(Rectangle&);
	void print();
protected:
	int m_x1, m_y1;
	int m_x2, m_y2;
	int m_w, m_h;
};

#endif /* RECTANGLE_H_ */
