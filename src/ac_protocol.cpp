#include "main.hpp"

void sendStateQuery(const uint8_t *data, size_t len, bool writeMode = false);

void send_query(query_t type, const uint8_t *data, size_t len, bool writeMode){
    switch(type){
        case TELEGRAM_STARTUP:
            break;
        case TELEGRAM_STATE_SET:
            break;
        case TELEGRAM_CONN_STATE:
            break;
        case TELEGRAM_PING:
            break;
    }
}

void parse_response(uint8_t *buffer, size_t len) {
    logSocket("New telegram: length: " + String(len) + " data: ");

    for(size_t i = 0; i < len; ++i) {
        logSocket("0x");
        if(buffer[i] < 0x10)
            logSocket("0");
        logSocket(String(buffer[i], HEX) + " ");
    }
    logSocket("\r\n");
}

void sendStateQuery(const uint8_t *data, size_t len, bool writeMode) {
    return;
}