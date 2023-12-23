#include "main.hpp"

WiFiServer wifiServer(3333);
WiFiClient socketClient;

void onConnected();

bool handleNewClient() {
    if (!wifiServer.hasClient())
        return false;

    if (!socketClient.connected()) { // equivalent to !serverClients[i].connected()
        socketClient = wifiServer.accept();
        socketClient.setNoDelay(true);
        onConnected();
    }

    return true;
}

void logSocket(String str) {
    if(socketClient.availableForWrite() < 1)
        return;

    socketClient.print(str);
}

void onConnected() {
    socketClient.println("socket connected");
    // socketClient.println("Firmware ver: " + String(FIRMWARE_VERSION));
    // if(LittleFS.exists("/device.json"))
    //     socketClient.println("device.json found");
    // if(LittleFS.exists("/uid.txt"))
    //     socketClient.println("uid.txt found");
}