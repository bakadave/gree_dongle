#ifndef __TYPES_H__
#define __TYPES_H__

#include <Arduino.h>
#include "protocol.h"

#define MAX_SSID_LENGTH 32
#define MAX_PSK_LENGTH 64
#define DEFAULT_HOSTNAME "esp8266-relay"

#define SW_VERSION "0.1.0"

enum class reset_reason_t:uint8_t {
    REASON_DEFAULT_RST      = 0,    /* normal startup by power on */
    REASON_WDT_RST          = 1,    /* hardware watch dog reset */
    REASON_EXCEPTION_RST    = 2,    /* exception reset, GPIO status won’t change */
    REASON_SOFT_WDT_RST     = 3,    /* software watch dog reset, GPIO status won’t change */
    REASON_SOFT_RESTART     = 4,    /* software restart ,system_restart , GPIO status won’t change */
    REASON_DEEP_SLEEP_AWAKE = 5,    /* wake up from deep-sleep */
    REASON_EXT_SYS_RST      = 6     /* external system reset */
};

struct wifiConfig_t {
    char ssid[MAX_SSID_LENGTH] = "Alpokalja_privat";
    char psk[MAX_PSK_LENGTH] = "Rendszergizda";
};

enum wifi_connection_status_t {
    WIFI_DISCONNECTED,
    WIFI_CONNECTED_NOIP,
    WIFI_CONNECTED
};

struct deviceState_t {
    wifi_connection_status_t wifi_status = WIFI_DISCONNECTED;
    bool fsOk = false;
    bool resetWifi = false;
};

struct ac_state_t {
    uint8_t power;
    uint8_t target_temp = MINIMUM_TARGET_TEMP;
    uint8_t op_mode;
    uint8_t fan_mode;
    uint8_t swing_mode;
    uint8_t preset;

};

struct deviceConfig_t {
    deviceState_t state;
    reset_reason_t rst;
    wifiConfig_t wifi;
};

#endif // __TYPES_H__