#include "KeyBoardButtonView.h"

KeyBoardButtonView::~KeyBoardButtonView()
{
	// TODO Auto-generated destructor stub
}

void KeyBoardButtonView::setKeyBoardPosition(int row, int column)
{
	m_keyBoard_position.row = row;
	m_keyBoard_position.column = column;
}

KeyBoardPosition KeyBoardButtonView::getKeyBoardPosition()
{
	return m_keyBoard_position;
}
