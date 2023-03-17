#include "NetworkDevice.h"
#include <ESP8266WiFi.h>
#include "MEEPROM.h"

NetworkDevice::NetworkDevice() {
	m_lastssid = m_lastPassword = String("");
}

void NetworkDevice::initialize() {
	String ssid, password;
	if ((ssid = MEEPROM::instance().read("Name")) != "" && (password =
			MEEPROM::instance().read("Pass")) != "") {
		connectToNetwork(ssid, password);
	}
}

bool NetworkDevice::connectToNetwork(String ssid, String password) {
	constexpr unsigned int MAX_CONNECTION_ESTABLISHING_DURATION_MS = 10000;
	if (WiFi.status() == WL_CONNECTED) {
		WiFi.disconnect();
	}
	WiFi.begin(ssid.c_str(), password.c_str());
	auto now = millis();
	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
		if (millis() - now >= MAX_CONNECTION_ESTABLISHING_DURATION_MS) {
			return false;
		}
	}
	m_lastssid = ssid;
	m_lastPassword = password;
	return true;
}

bool NetworkDevice::getStatus() {
	return (WiFi.status() == WL_CONNECTED);
}

Network NetworkDevice::getCurrentNetwork() {
	return Network { WiFi.SSID(), WiFi.psk(), WiFi.RSSI(), WiFi.BSSID() };
}

String NetworkDevice::invokeGetURL(String host, String add_on_url) {
	WiFiClient client;
	String response = "";
	if (client.connect(host.c_str(), 80)) {
		client.print(
				String("GET " + add_on_url) + " HTTP/1.1\r\n" + "Host: " + host
						+ "\r\n" + "Connection: close\r\n" + "\r\n");

		if (client.available()) {
			response = client.readStringUntil('\n');
		}
	}
	client.stop();
	return response;
}

String NetworkDevice::invokePostURL(String host, String add_on_url,
		String data) {
	String linesep="\r\n";

	auto post_format = [&]() -> String{
		String format = "";
		format += String("POST ") + add_on_url + String(" HTTP/1.1") + linesep;
		format += String(String("Host: ") + host) + linesep;
		format += String("Content-Type: application/json") + linesep;
		format += String("Cache-Control: no-cache") + linesep;
		format += String("Content-Length: ");
		format += String(data.length()) + linesep;
		format += linesep;
		format += data;
		return format;
	};

	WiFiClient client;
	String response = "";

	if (client.connect(host.c_str(), 80)) {
		Serial.println("Connected!");
		auto msg = post_format();
		Serial.println(msg);
		client.print(msg);
		response = client.readString();
	}
	client.stop();
	return response;
}

std::vector<Network> NetworkDevice::getAllNetworks() {
	int n = WiFi.scanNetworks(false, true);
	std::vector<Network> networks;
	for (int i = 0; i < n; i++) {
		uint8_t tmp_encryptionType;
		int32_t tmp_channel;
		bool tmp_isHidden;

		Network tmp_network;
		String tmp_network_ssid(tmp_network.ssid.c_str());

		WiFi.getNetworkInfo(i, tmp_network_ssid, tmp_encryptionType,
				tmp_network.rssi, tmp_network.bssid, tmp_channel, tmp_isHidden);
		tmp_network.ssid = tmp_network_ssid;

		networks.push_back(tmp_network);
	}
	return networks;
}
