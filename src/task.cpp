#include "main.hpp"
#include <TaskScheduler.h>

Scheduler ts;

const uint8_t startupTelegram[] = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x28, 0x1e, 0x19, 0x23, 0x23, 0x00};   // 10 telegram: check digit = 0xb8
const uint8_t connStateTelegram[] = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7e};             // 0E telegram: check digit = 0x0f
const uint8_t pingTelegram[] = {0x04, 0x07, 0x00, 0x00};                                                                        // 05 telegram: check digit = 0x10

void gree_callback();
bool gree_enable();
void gree_disable();
void socket_callback();
bool socket_onEnable();
void socket_onDisable();

Task gree_t(TASK_SECOND, TASK_FOREVER, &gree_callback, &ts, false, &gree_enable, &gree_disable);
// Task gree_ping_t(TASK_SECOND * 10, TASK_FOREVER, &gree_callback, &ts, false, &gree_enable, &gree_disable);
// Task gree_conn_t(TASK_SECOND * 10, TASK_FOREVER, &gree_callback, &ts, false, &gree_enable, &gree_disable);
// Task gree_state_t(TASK_SECOND * 10, TASK_FOREVER, &gree_callback, &ts, false, &gree_enable, &gree_disable);
Task t_socket(TASK_IMMEDIATE, TASK_FOREVER, &socket_callback, &ts, true, &socket_onEnable, &socket_onDisable);

void gree_callback() {
    
}

bool gree_enable() {
    send_query(TELEGRAM_STARTUP, startupTelegram, sizeof(startupTelegram));
    return true;
}

void gree_disable() {
    Serial.println("gree_disable");
}

void socket_callback() {
    handleNewClient();
}

bool socket_onEnable() {
    wifiServer.begin();
    return true;
}

void socket_onDisable() {
    wifiServer.close();
}