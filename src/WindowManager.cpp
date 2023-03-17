#include "WindowManager.h"

#include "NetworkViewFirst.h"
#include "NetworkViewSecond.h"
#include "ViewAllDetails.h"
#include "ViewDetailGraph.h"
#include "ViewAllDetailsGraphs.h"
#include "Status.h"
#include "RelayView.h"
#include <cJSON.h>

#include <fstream>

using namespace std;

/*

{
    "relaynames": ["r1", "r2", "r3", "r4", "r5"]
}

*/

cJSON* getRelayNamesJSON(void)
{
	std::vector<std::string> relay_names = { "R1", "R2", "R3", "R4", "R5" };

	cJSON *json = cJSON_CreateObject();
	cJSON *rnames = cJSON_CreateArray();
	cJSON *rname = NULL;

	cJSON_AddItemToObject(json, "relayNames", rnames);

	for (auto &relay_name : relay_names)
	{
		rname = cJSON_CreateString(relay_name.c_str());
		cJSON_AddItemToArray(rnames, rname);
	}

	return json;
}

std::vector<std::string> getRelayNamesFromJSON(cJSON *json) {
	std::vector<std::string> relay_names;
	cJSON *rnames = cJSON_GetObjectItem(json, "relayNames");
	cJSON *rname = NULL;
	cJSON_ArrayForEach(rname, rnames) {
		if (cJSON_IsString(rname)) {
			relay_names.push_back(rname->valuestring);
		}
	}
	return relay_names;
}


void WindowManager::initialize(SensorController* sc, TftDisplay *tft, NetworkDevice *networkDevice)
{
	m_dirty = false;
	m_sensor_count = sc->getSensorCount();
	for (unsigned int i = 0; i < m_sensor_count; i++) {
		String name;
		name += 'S';
		name += i;

//		Serial.print("Name: ");
//		Serial.println(name);

		WindowLinkage windowLinkage { name, new ViewDetailGraph(tft, sc->getSensor(i), this) };
		m_windows.push_back(windowLinkage);
	}
	WindowLinkage d1 = { "D1", new ViewAllDetails(tft, sc, this) };
	WindowLinkage dg1 = { "DG1", new ViewAllDetailsGraphs(tft, sc, this) };
	WindowLinkage st1 = { "ST1", new Status(tft, sc, this, networkDevice) };
	WindowLinkage n1 = { "N1", new NetworkViewFirst(tft, this, networkDevice) };
	WindowLinkage n2 = { "N2", new NetworkViewSecond(tft, this, (NetworkViewFirst *)n1.window) };

	std::vector<std::string> relay_std_names = getRelayNamesFromJSON(getRelayNamesJSON());
	std::vector<String> relay_names;

	for(auto &relay_std_name : relay_std_names){
		relay_names.push_back(relay_std_name.c_str());
		// Serial.println(relay_std_name.c_str());
	}

	WindowLinkage r1 = { "R1", new RelayView(tft, this, relay_names)};

	m_windows.push_back(d1);
	m_windows.push_back(dg1);
	m_windows.push_back(st1);
	m_windows.push_back(n1);
	m_windows.push_back(n2);
	m_windows.push_back(r1);
	setCurrentView("D1");
}

WindowManager::~WindowManager()
{
	for (vector<WindowLinkage>::iterator it = m_windows.begin(); it != m_windows.end(); it++) {
		delete (*it).window;
	}
}

void WindowManager::setDirty(bool b)
{
	m_dirty = b;
}

bool WindowManager::getDirty()
{
	return m_dirty;
}

void WindowManager::setCurrentView(String name)
{
	Window *window = lookup(name);
	if (window != nullptr) {
		m_currentWindow = window;
	} else {
	}
	m_dirty = true;
}

void WindowManager::setCurrentView(Window *window)
{
	if(window != nullptr){
		m_currentWindow = window;
	}
	m_dirty = true;
}

Window *WindowManager::lookup(String name)
{
	for (auto& it : m_windows) {
		if (it.name == name) {
			return it.window;
		}
	}
	return nullptr;
}

unsigned int WindowManager::getSensorCount()
{
	return m_sensor_count;
}

void WindowManager::draw()
{
	if (m_dirty) {
		m_currentWindow->beforeEntrance();
		m_dirty = false;
	}
	m_currentWindow->draw();
}

void WindowManager::up()
{
	m_currentWindow->up();
}
void WindowManager::left()
{
	m_currentWindow->left();
}
void WindowManager::down()
{
	m_currentWindow->down();
}
void WindowManager::right()
{
	m_currentWindow->right();
}
void WindowManager::specialButton()
{
	m_currentWindow->specialButton();
}
