#ifndef KEYBOARDVIEW_H_
#define KEYBOARDVIEW_H_

#include <vector>

#include "CommonKeyBoardLayout.h"
#include "ViewComposite.h"
#include "KeyBoardButtonView.h"

class KeyBoardView: public ViewComposite
{
	enum class Direction
		: int {
			UP, DOWN, LEFT, RIGHT
	};

public:
	KeyBoardView(TftDisplay *tft, int x1, int y1, int w, int h) :
			ViewComposite(tft)
	{
		setPosition(x1, y1);
		newButtonPosition = getPosition();
		m_forceDraw = true;
		m_capsLock = false;
		prev_row = 10000;

		setFrame(x1, y1, x1 + w, y1 + h);
		// setFrameColor(ORANGE);
		initKeys();

		m_selectedButton = getButton(0, 0);
		m_lastSelectedButton = m_selectedButton;
		m_selectedButton->select();

		m_current_view = m_views.begin();
	}
	;
	virtual ~KeyBoardView();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	KeyBoardButtonView *getSelectedButton();
	virtual void draw();
	void selectPreSelectedButton();
	void setForceDraw(bool b);
	bool getForceDraw();
	void toggleCapsLock();
	void printAllButtons();
protected:
	CommonKeyBoardLayout *m_keyBoardLayout;
	KeyBoardButtonView *m_selectedButton;
	KeyBoardButtonView *m_preSelectedButton;
	KeyBoardButtonView *m_lastSelectedButton;
	bool m_forceDraw;bool m_capsLock;

	void initKeys();
private:
	void move(Direction);
	KeyBoardButtonView* getOverFlowedButton(KeyBoardButtonView *, Direction);
	KeyBoardButtonView* getClosestButton(KeyBoardButtonView*, Direction);
	KeyBoardButtonView* getClosestButton(KeyBoardButtonView*, int row);
	KeyBoardButtonView* getButton(int row, int column);
	bool addButton(KeyBoardButtonView* button, String text, int row);
	int prev_row;
	Position newButtonPosition;
};

#endif /* KEYBOARDVIEW_H_ */
