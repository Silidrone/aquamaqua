/* Required Libraries  */
#include "Arduino.h"
#include <Timer.h>
#include <Event.h>
#include <algorithm>
#include <string>

#include "MEEPROM.h"
#include "SensorController.h"
#include "TftDisplay.h"
#include "InputController.h"
#include "WindowManager.h"
#include "KeyBoardDeviceInput.h"
#include "ButtonView.h"
#include "HelperFunctions.h"
#include "ListButtonView.h"
#include <cJSON.h>
	
/* Objects (Instances) */
Timer *timer;
SensorController sensorController;
InputController inputController;
TftDisplay tft;
NetworkDevice networkDevice;
WindowManager viewManager;
KeyBoardDeviceInput keyBoardDevice;

/* Timer-related variables */
int updateTimer, drawTimer, inputControlTimer;

void callCheckInputs()
{
	inputController.checkInputs();
}

void callDraw()
{
	viewManager.draw();
}

void uploadSensorValues(){
	auto sensors = sensorController.getSensors();
	for(auto& sensor : sensors){
		String sensor_name(sensor->getName());
		sensor_name = HelperFunctions::instance().withoutWhiteSpaces(sensor_name);
		String sensor_value(sensor->getQueriedValue());

		// Serial.print(sensor_name);
		// Serial.print(": ");
		// Serial.println(sensor_value);

		networkDevice.invokeGetURL("am.lappasoft.com", String("/u/sensor_val_" + sensor_name + '=' + sensor_value));
	}
}

void callUpdate()
{
	sensorController.update();
	uploadSensorValues();
}

void callRight()
{
	Serial.println("Right");
	viewManager.right();
}

void callLeft()
{
	Serial.println("Left");
	viewManager.left();
}

void callDown()
{
	Serial.println("Down");
	viewManager.down();
}

void callUp()
{
	Serial.println("Up");
	viewManager.up();
}

void callSpecialButton()
{
	Serial.println("Special Button");
	viewManager.specialButton();
}

void setup()
{
	Serial.begin(9600);
	Serial.println("start");

	sensorController.initialize();
	inputController.initialize();
	tft.init();

	TextView *m_loadingText = new TextView(&tft);
	m_loadingText->setPosition(TFTWIDTH / 2,  TFTHEIGHT / 2);
	m_loadingText->setText("Loading...");
	m_loadingText->expandFrameForText();
	m_loadingText->setPosition(m_loadingText->getPosition().x - (m_loadingText->getFrame().getW() / 2), m_loadingText->getPosition().y - (m_loadingText->getFrame().getH() / 2));
	m_loadingText->expandFrameForText();
	m_loadingText->setFrameColor(BLACK);
	tft.clearScreen();
	m_loadingText->draw();

	networkDevice.initialize();
	viewManager.initialize(&sensorController, &tft, &networkDevice);
	keyBoardDevice.initialize();

	timer = new Timer();
	updateTimer = timer->every(10000, &callUpdate);
	drawTimer = timer->every(10, &callDraw);
	inputControlTimer = timer->every(10, &callCheckInputs);

	inputController.addLinkage(keyBoardDevice.getUp(), &callUp);
	inputController.addLinkage(keyBoardDevice.getDown(), &callDown);
	inputController.addLinkage(keyBoardDevice.getLeft(), &callLeft);
	inputController.addLinkage(keyBoardDevice.getRight(), &callRight);
	inputController.addLinkage(keyBoardDevice.getSpecial(), &callSpecialButton);

	MEEPROM::instance().reset();
	MEEPROM::instance().printEEPROM();
	networkDevice.connectToNetwork("network_name", "password");
	networkDevice.invokePostURL("am.lappasoft.com", "/api/u/", data);
}

void loop()
{
	timer->update();
}