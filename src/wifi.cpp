#include "main.hpp"

WiFiEventHandler connectedEventHandler, gotIpEventHandler, disconnectedEventHandler;

void setupWiFi_STA() {
    WiFi.mode(WIFI_STA);
    WiFi.setAutoConnect(false);
    WiFi.setAutoReconnect(true);

    connectedEventHandler = WiFi.onStationModeConnected([](const WiFiEventStationModeConnected& event){
        //Serial.println("WiFi station connected to: '" + event.ssid + "' channel: " + String(event.channel));
        deviceConfig.state.wifi_status = WIFI_DISCONNECTED;
    });

    gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP& event){
        //Serial.println("DHCP got IP: " + event.ip.toString());
        deviceConfig.state.wifi_status = WIFI_CONNECTED;
        //digitalWrite(LED, LED_OFF);
    });

    disconnectedEventHandler = WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected& event){
        //Serial.println("WiFi connection lost, reason: " + String(event.reason));
        deviceConfig.state.wifi_status = WIFI_CONNECTED_NOIP;
        //digitalWrite(LED, LED_ON);
    });

    WiFi.begin(deviceConfig.wifi.ssid, deviceConfig.wifi.psk);   
}

void setupWiFi_AP() {
    return;
    }