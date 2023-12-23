#include <main.hpp>

deviceConfig_t deviceConfig;

void setup() {
    Serial.begin(BAUDRATE, SERIAL_8E1, SERIAL_FULL);
    Serial.setTimeout(SERIAL_TIMEOUT);

    if(strcmp(deviceConfig.wifi.ssid, "") == 0) {
        setupWiFi_AP();
        return; // exit setup, don't start tasks
    }
 
    setupWiFi_STA();
}

void loop() {
    ts.execute();
}

void serialEvent() {
    /** if Serial.available() > 0 read the first two bytes
     * if those bytes are the preamble bytes, read the third byte which defines length, put the message in a buffer and call parser
     * else throw it away
    */
    if(Serial.available() > 0) {
        uint8_t preamble[2];
        Serial.readBytes(preamble, 2);
        if(memcmp(preamble, gree_preamble, gree_preamble_len) == 0) {
            size_t length = (uint8_t)Serial.read();
            uint8_t buffer[length];
            Serial.readBytes(buffer, length);
            parse_response(buffer, length);
        }
    }
}