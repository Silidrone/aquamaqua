#include <ESP8266WiFi.h>
#include <vector>

struct Network
{
	String ssid;
	String password;
	int32_t rssi;
	uint8_t* bssid;
};

std::vector<Network> getAllNetworks();

void setup()
{
	Serial.begin(9600);
	Serial.println();

	auto networks = getAllNetworks();
	for(auto& network : networks){
		Serial.println("network exists");
	}
}

void loop() {}

std::vector<Network> getAllNetworks()
{
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);

	int n = WiFi.scanNetworks(false, true);
	std::vector<Network> networks;
	for (int i = 0; i < n; i++) {
		uint8_t tmp_encryptionType;
		int32_t tmp_channel;
		bool tmp_isHidden;

		Network tmp_network;

		WiFi.getNetworkInfo(i, tmp_network.ssid, tmp_encryptionType, tmp_network.rssi, tmp_network.bssid, tmp_channel, tmp_isHidden);
		networks.push_back(tmp_network);
	}
	return networks;
}