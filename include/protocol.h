#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#define TELEGRAM_HEADER 0x7E
#define MINIMUM_TARGET_TEMP 16

const size_t gree_preamble_len = 2;
const uint8_t gree_preamble[gree_preamble_len] = {0x7E, 0x7E};

// enum telegram_t {
//     TELEGRAM_STARTUP,           // 0x10
//     TELEGRAM_STARTUP_RESP,      // 0x03
//     TELEGRAM_COMMAND_SET,       // 0x2c
//     TELEGRAM_COMMAND_RESP,      // 0x2f
//     TELEGRAM_PING,              // 0x05
//     TELEGRAM_CONN_STATE,        // 0x0e
//     TELEGRAM_UNKNOWN            // 0x1a
// };

enum query_t {
    TELEGRAM_STARTUP,           // 0x10
    TELEGRAM_STATE_SET,         // 0x2c
    TELEGRAM_CONN_STATE,        // 0x0e
    TELEGRAM_PING,              // 0x05
};

enum response_t {
    TELEGRAM_STARTUP_RESP,      // 0x03
    TELEGRAM_COMMAND_RESP,      // 0x2f
    TELEGRAM_UNKNOWN            // 0x1a
};

enum gree_mode_t:uint8_t {
    GREE_MODE_OFF = 0x10,
    GREE_MODE_AUTO = 0x80,
    GREE_MODE_COOL = 0x90,
    GREE_MODE_DRY = 0xA0,
    GREE_MODE_FAN = 0x80,
    GREE_MODE_HEAT = 0xC0
};

enum gree_fan_t:uint8_t {
    GREE_FAN_AUTO = 0x00,
    GREE_FAN_LOW = 0x01,
    GREE_FAN_MEDIUM = 0x02,
    GREE_FAN_HIGH = 0x03
};

enum ac_swing:uint8_t {
    GREE_SWING_OFF = 0x44,
    GREE_SWING_VERTICAL = 0x14,
    GREE_SWING_HORIZONTAL = 0x41,
    GREE_SWING_BOTH = 0x11
};

enum ac_partial_swing_t:uint8_t {
  GREE_PARTIAL_SWING_OFF = 0x00,
  GREE_PARTIAL_SWING_FULL = 0x10,
  GREE_PARTIAL_SWING_TOP = 0x20,
  GREE_PARTIAL_SWING_ABOVEMIDDLE = 0x30,
  GREE_PARTIAL_SWING_MIDDLE = 0x40,
  GREE_PARTIAL_SWING_BELOWMIDDLE = 0x50,
  GREE_PARTIAL_SWING_BOTTOM = 0x60,
  GREE_PARTIAL_SWING_MIDDLE_TO_BOTTOM = 0x70,
  GREE_PARTIAL_SWING_ABOVEMIDDLE_TO_BELOWMIDDLE = 0x90,
  GREE_PARTIAL_SWING_MIDDLE_TO_TOP = 0xB0
};

#endif  // __PROTOCOL_H__