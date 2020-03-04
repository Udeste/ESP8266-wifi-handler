#include "IPAddress.h"
#include <ESP8266WiFi.h>
#include "Arduino.h"

#define MAX_WIFI_OUTPUT_POWER 20.5

class ESP8266WifiHandler {
  public:
    ESP8266WifiHandler  (const char* ssid, const char* password, uint8_t chan);
    void         startAP               ();
    void         startSTA              ();
    void         disconnect            ();
    bool         isClientConnected     ();
    void         setWifiPower          (float dbm);
    void         powerOff              ();
    bool         isWifiON              ();

  private:
    const char*  ssid;
    const char*  password;
    uint8_t      chan;
    IPAddress    local_IP;
};
