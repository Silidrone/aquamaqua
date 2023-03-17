#include "NetworkViewSecond.h"

NetworkViewSecond::~NetworkViewSecond()
{
	delete m_loadingText;
}

void NetworkViewSecond::init(TftDisplay *tft)
{
	m_keyBoardView = new KeyBoardView(tft, 7, 70, TFTWIDTH - 5, (TFTHEIGHT / 2) - 10);
	addView(m_keyBoardView);

	m_loadingText = new TextView(m_tft);
	m_loadingText->setPosition(TFTWIDTH / 2,  TFTHEIGHT / 2);
	m_loadingText->setText("Loading...");
	m_loadingText->expandFrameForText();
	m_loadingText->setPosition(m_loadingText->getPosition().x - (m_loadingText->getFrame().getW() / 2), m_loadingText->getPosition().y - (m_loadingText->getFrame().getH() / 2));
	m_loadingText->expandFrameForText();
	m_loadingText->setFrameColor(BLACK);

	m_inputBox = new InputBoxView(tft);

	m_inputBox->setFrame(9, 40, 110, 60);
	m_inputBox->setFrameColor(RED);
	m_inputBox->setTextColor(RED);
	m_inputBox->setDescription("Password");
	addView(m_inputBox);
}

void NetworkViewSecond::draw(){
	Window::draw();
	if(m_forceDraw){
		m_tft->text("Name: " + m_networkViewFirst->getSelectedNetworkName(), 10, 10, GREEN);
		m_forceDraw = false;
	}
}

void NetworkViewSecond::up()
{
	m_keyBoardView->moveUp();
	m_keyBoardView->selectPreSelectedButton();
}

void NetworkViewSecond::down()
{
	m_keyBoardView->moveDown();
	m_keyBoardView->selectPreSelectedButton();
}

void NetworkViewSecond::right()
{
	m_keyBoardView->moveRight();
	m_keyBoardView->selectPreSelectedButton();
}

void NetworkViewSecond::left()
{
	m_keyBoardView->moveLeft();
	m_keyBoardView->selectPreSelectedButton();
}

void NetworkViewSecond::specialButton()
{
	ButtonView* selectedButton = m_keyBoardView->getSelectedButton();
	String text = selectedButton->getText();
	if (text == "CAPS") {
		m_keyBoardView->toggleCapsLock();
	}
	else if (text == "DEL") {
		m_inputBox->kickLastChar();
	}
	else if (text == "NEXT") {
		nextClicked();
	}
	else if (text == "BACK"){
		m_windowManager->setCurrentView("N1");
	}
	else if(text == "CL"){
		m_inputBox->clearText();
	}
	else {
		m_inputBox->appendText(text);
	}
}

void NetworkViewSecond::setForceDraw(bool b){
	m_forceDraw = b;
}

void NetworkViewSecond::nextClicked()
{
	String name = m_networkViewFirst->getSelectedNetworkName();
	String password = m_inputBox->getText();

	m_tft->clearScreen();
	m_loadingText->draw();

	bool connected = m_networkViewFirst->getNetworkDevice()->connectToNetwork(name, password);

	if(connected){
		MEEPROM::instance().write("Name", name);
		MEEPROM::instance().write("Pass", password);
	}
	m_windowManager->setCurrentView("ST1");
}

void NetworkViewSecond::beforeEntrance()
{
	Window::beforeEntrance();
	m_keyBoardView->setForceDraw(true);
	m_inputBox->setForceDraw(true);
	setForceDraw(true);
	String name = m_networkViewFirst->getSelectedNetworkName();
	String password = MEEPROM::instance().read("Pass");
	String last_name = MEEPROM::instance().read("Name");

	if(name == last_name){
		if(password != ""){
			m_inputBox->setText(password);
		}
	}else{
		m_inputBox->clearText();
	}
}

