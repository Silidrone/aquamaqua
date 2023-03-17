#ifndef WINDOWMANAGER_H_
#define WINDOWMANAGER_H_

class Window;

#include <vector>
#include "SensorController.h"
#include "TftDisplay.h"
#include "NetworkDevice.h"

struct WindowLinkage
{
	String name;
	Window* window;
};

class WindowManager
{
public:
	void initialize(SensorController* sc, TftDisplay *tft, NetworkDevice *networkDevice);
	virtual ~WindowManager();

	void draw();
	void up();
	void left();
	void down();
	void right();
	void specialButton();

	void setCurrentView(String);
	void setCurrentView(Window *);

	void setDirty(bool);
	bool getDirty();

	unsigned int getSensorCount();
protected:
	std::vector<WindowLinkage> m_windows;
	Window *m_currentWindow;
	Window *lookup(String);
	unsigned int m_sensor_count;
	bool m_dirty;
};

#endif /* WINDOWMANAGER_H_ */
