#include "Textable.h"

Textable::~Textable()
{

}

void Textable::setText(String text){
	m_text = text;
}

String Textable::getText(){
	return m_text;
}

void Textable::setTextColor(unsigned int color){
	m_textColor = color;
}
