#ifndef NETWORKDEVICE_H_
#define NETWORKDEVICE_H_

#include "Arduino.h"
#include <vector>

#define MAXIMUM_RSSI_VALUE 100

struct Network
{
	String ssid;
	String password;
	int32_t rssi;
	uint8_t* bssid;
};

class NetworkDevice
{
public:
	NetworkDevice();
	void initialize();
	bool connectToNetwork(String, String);
	bool getStatus();
	String invokeGetURL(String, String);
	String invokePostURL(String, String, String);
	Network getCurrentNetwork();
	std::vector<Network> getAllNetworks();
protected:
	String m_lastssid, m_lastPassword;
};

#endif /* NETWORKDEVICE_H_ */
