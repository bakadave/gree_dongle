#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <TaskSchedulerDeclarations.h>  // https://github.com/arkhipenko/TaskScheduler/issues/15#issuecomment-369314767

#include "protocol.h"
#include "types.h"

#define BAUDRATE 4800
#define SERIAL_TIMEOUT 500

extern deviceConfig_t deviceConfig;
extern WiFiServer wifiServer;
extern Scheduler ts;

// ac_protocol.cpp
void send_query(query_t type, const uint8_t *data, size_t len, bool writeMode = false);
void parse_response(uint8_t *buffer, size_t len);

//socket_debug
extern bool handleNewClient();
extern void logSocket(String str);

// wifi.cpp
void setupWiFi_STA();
void setupWiFi_AP();