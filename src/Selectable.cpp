#include "Selectable.h"

Selectable::~Selectable()
{
}

void Selectable::select()
{
	m_selected = true;
}

void Selectable::deselect()
{
	m_selected = false;
}

bool Selectable::isSelected()
{
	return m_selected;
}
