#include "wifi-handler.h"

ESP8266WifiHandler::ESP8266WifiHandler(const char* ssid, const char* password, uint8_t chan) {
  this->ssid = ssid;
  this->password = password;
  this->chan = chan;
}

void ESP8266WifiHandler::startAP() {
  WiFi.mode(WIFI_AP);
  WiFi.encryptionType(AUTH_WPA2_PSK);
  WiFi.softAP(ssid, password, chan);
  local_IP = WiFi.softAPIP();
}

void ESP8266WifiHandler::startSTA() {
  WiFi.mode(WIFI_STA);
  WiFi.encryptionType(AUTH_WPA2_PSK);
  WiFi.begin(ssid, password, chan);
  local_IP = WiFi.localIP();
  WiFi.setAutoReconnect(true);
}

bool ESP8266WifiHandler::isWifiON() {
  return WiFi.getMode() != WIFI_OFF;
}

void ESP8266WifiHandler::disconnect() {
  WiFi.disconnect();
}

bool ESP8266WifiHandler::isClientConnected() {
  return isWifiON() && wifi_softap_get_station_num() > 0;
}

void ESP8266WifiHandler::setWifiPower(float dbm) {
  WiFi.setOutputPower(dbm);
}

void ESP8266WifiHandler::powerOff() {
  disconnect();
  WiFi.mode(WIFI_OFF);
}
