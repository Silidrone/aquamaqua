#include "KeyBoardView.h"

KeyBoardView::~KeyBoardView()
{
	delete m_keyBoardLayout;
}

void KeyBoardView::initKeys()
{
	CommonKeyBoardLayout *keyBoardLayout = new CommonKeyBoardLayout();

	for (int currentRow = 0; currentRow < keyBoardLayout->getRowCount(); currentRow++) {
		for (int currentColumn = 0, addedOffset = 0; currentColumn < keyBoardLayout->getColumnCount(currentRow); currentColumn++) {
			KeyBoardButtonView *currentButton = new KeyBoardButtonView(m_tft);
			String currentText = keyBoardLayout->getKey(currentRow, currentColumn);
			currentButton->setCapsLock(true);

			if (addedOffset > 0 || addButton(currentButton, currentText, currentRow) == false) { // if false is returned, a button couldnt fit in that row
				keyBoardLayout->deleteKey(currentRow, currentColumn);
				currentColumn--;
				if (currentRow + 1 < keyBoardLayout->getRowCount()) { // check whether there is a row below this one
					keyBoardLayout->insertKey(currentRow + 1, addedOffset++, currentText);
				}
				else {
					std::vector<String> newRow = { currentText };
					keyBoardLayout->pushBackRow(newRow);
					addedOffset = 1; // as one column is added immidiately, this should be set to 1
				}
				delete currentButton;
			}
			else {
				currentButton->setKeyBoardPosition(currentRow, currentColumn);
				currentButton->setTextColor(GREEN);
				currentButton->setFrameColor(RED);
			}
		}
	}

	m_keyBoardLayout = keyBoardLayout;
}

bool KeyBoardView::addButton(KeyBoardButtonView* button, String text, int row)
{
	constexpr unsigned int key_gap_x = 2;
	constexpr unsigned int key_gap_y = 1;

	if (prev_row != row) {
		newButtonPosition.x = getPosition().x + key_gap_x;
		if (row == 0) {
			newButtonPosition.y += key_gap_y;
		}
		else {
			newButtonPosition.y += ButtonView::getTextHeight() + key_gap_y;
		}
		button->setPosition(newButtonPosition.x, newButtonPosition.y);
	}
	else {
		button->setPosition(newButtonPosition.x + key_gap_x, newButtonPosition.y);
	}

	if (button->calculateFrame(text).getX2() >= this->m_frame.getX2() - key_gap_x) {
		return false;
	}

	button->setText(text);
	button->expandFrameForText();
	addView(button);

	newButtonPosition.x = button->calculateFrame(text).getX2();
	prev_row = row;

	return true;
}

void KeyBoardView::selectPreSelectedButton()
{
	if (m_preSelectedButton == nullptr) {
		return;
	}

	m_selectedButton->deselect();
	m_lastSelectedButton = m_selectedButton;

	m_selectedButton = m_preSelectedButton;
	m_selectedButton->select();
}

void KeyBoardView::draw()
{
	if (m_forceDraw) {
		std::vector<ViewBase *>::iterator it;
		// drawFrame();

		for (it = m_views.begin(); it != m_views.end(); it++) {
			KeyBoardButtonView *currentButton = (KeyBoardButtonView*) *it;

			if (!(m_keyBoardLayout->isSpecialKey(currentButton->getText()))) {
				currentButton->setCapsLock(m_capsLock);
			}
			currentButton->draw();
		}
		m_forceDraw = false;
	}
	if (m_lastSelectedButton != m_selectedButton) {
		m_selectedButton->eraseFrame();
		m_selectedButton->drawFrame();
		m_lastSelectedButton->eraseFrame();
		m_lastSelectedButton->drawFrame();
		m_lastSelectedButton = m_selectedButton;
	}
}

void KeyBoardView::move(Direction direction)
{
	KeyBoardButtonView *button = nullptr;

	if (direction == Direction::UP || direction == Direction::DOWN) {
		button = getClosestButton(m_selectedButton, direction);
	}
	else if (direction == Direction::LEFT) {
		button = getButton(m_selectedButton->getKeyBoardPosition().row, m_selectedButton->getKeyBoardPosition().column - 1);
	}
	else if (direction == Direction::RIGHT) {
		button = getButton(m_selectedButton->getKeyBoardPosition().row, m_selectedButton->getKeyBoardPosition().column + 1);
	}
	if (button != nullptr) {
		m_preSelectedButton = button;
	}
	else {
		button = getOverFlowedButton(m_selectedButton, direction);
		if (button != nullptr) {
			m_preSelectedButton = button;
		}
	}
}

void KeyBoardView::moveUp()
{
	move(Direction::UP);
}

void KeyBoardView::moveDown()
{
	move(Direction::DOWN);
}

void KeyBoardView::moveLeft()
{
	move(Direction::LEFT);
}

void KeyBoardView::moveRight()
{
	move(Direction::RIGHT);
}

void KeyBoardView::setForceDraw(bool b)
{
	m_forceDraw = b;
}

bool KeyBoardView::getForceDraw()
{
	return m_forceDraw;
}

void KeyBoardView::toggleCapsLock()
{
	m_capsLock = !m_capsLock;
	m_forceDraw = true;
}

KeyBoardButtonView* KeyBoardView::getSelectedButton()
{
	return m_selectedButton;
}

KeyBoardButtonView* KeyBoardView::getClosestButton(KeyBoardButtonView *the_button, Direction direction)
{
	if (direction == Direction::UP) {
		return getClosestButton(the_button, the_button->getKeyBoardPosition().row - 1);
	}
	else if (direction == Direction::DOWN) {
		return getClosestButton(the_button, the_button->getKeyBoardPosition().row + 1);
	}

	return nullptr;
}

KeyBoardButtonView* KeyBoardView::getClosestButton(KeyBoardButtonView *the_button, int row)
{
	if (the_button == nullptr || getButton(row, 0) == nullptr) {
		return nullptr;
	}

	int smallest_x_difference = this->getFrame().getX2() + 1;
	KeyBoardButtonView *return_button = nullptr;

	for (int colIterator = 0; colIterator < m_keyBoardLayout->getColumnCount(row); colIterator++) {
		KeyBoardButtonView *button = getButton(row, colIterator);
		Rectangle the_button_frame = the_button->getFrame();
		Rectangle button_frame = button->getFrame();
		int button_center = button_frame.getX1() + (button_frame.getW() / 2);
		int the_button_center = the_button_frame.getX1() + (the_button_frame.getW() / 2);

		int x_difference = abs(button_center - the_button_center);
		if (x_difference < smallest_x_difference) {
			smallest_x_difference = x_difference;
			return_button = button;
		}
	}
	return return_button;
}

KeyBoardButtonView* KeyBoardView::getOverFlowedButton(KeyBoardButtonView *button, Direction direction)
{
	if (button == nullptr) {
		return nullptr;
	}

	KeyBoardPosition button_keyBoardPosition = button->getKeyBoardPosition();

	int first_row = 0;
	int last_row = m_keyBoardLayout->getRowCount() - 1;

	if (direction == Direction::UP && button_keyBoardPosition.row != first_row) {
		return nullptr;
	}

	if (direction == Direction::DOWN && button_keyBoardPosition.row != last_row) {
		return nullptr;
	}

	if (direction == Direction::UP) {
		return getClosestButton(button, last_row);
	}
	else if (direction == Direction::DOWN) {
		return getClosestButton(button, first_row);
	}

	if (direction == Direction::LEFT) {
		if (button_keyBoardPosition.row == first_row && button_keyBoardPosition.column == 0) {
			return getButton(last_row, m_keyBoardLayout->getColumnCount(last_row) - 1);
		}
		else if (button_keyBoardPosition.column == 0) {
			int prev_row = button_keyBoardPosition.row - 1;
			return getButton(prev_row, m_keyBoardLayout->getColumnCount(prev_row) - 1);
		}
	}

	if (direction == Direction::RIGHT) {
		if (button_keyBoardPosition.row == last_row && button_keyBoardPosition.column == m_keyBoardLayout->getColumnCount(last_row) - 1) {
			return getButton(first_row, 0);
		}
		else if (button_keyBoardPosition.column == m_keyBoardLayout->getColumnCount(button_keyBoardPosition.row) - 1) {
			int next_row = button_keyBoardPosition.row + 1;
			return getButton(next_row, 0);
		}
	}

	return nullptr;
}

KeyBoardButtonView* KeyBoardView::getButton(int row, int column)
{
	for (auto it = m_views.begin(); it != m_views.end(); it++) {
		KeyBoardButtonView *button = (KeyBoardButtonView *) *it;
		KeyBoardPosition button_keyBoardPosition = button->getKeyBoardPosition();
		if (button_keyBoardPosition.row == row && button_keyBoardPosition.column == column) {
			return button;
		}
	}
	return nullptr;
}

void KeyBoardView::printAllButtons()
{
	for (auto& it : m_views) {
		KeyBoardButtonView *bp = (KeyBoardButtonView *) it;
		// Serial.print(bp->getText().c_str());
		// Serial.print(" | X: ");
		// Serial.print(bp->getKeyBoardPosition().row);
		// Serial.print(", Y: ");
		// Serial.println(bp->getKeyBoardPosition().column);
	}
}
