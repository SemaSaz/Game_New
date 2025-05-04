#include "JoystickHandler.h"
#include <Arduino.h>

String joystickPositionToString(JoystickPosition pos) {
    switch (pos) {
    case JoystickPosition::Center: return "Center";
    case JoystickPosition::Up:     return "Up";
    case JoystickPosition::Down:   return "Down";
    case JoystickPosition::Left:   return "Left";
    case JoystickPosition::Right:  return "Right";
    default:                       return "Unknown";
    }
}

JoystickPosition JoystickHandler::pollJoystick() {

    int randomValue = 1;

    switch (randomValue) {
    case 0: return JoystickPosition::Center;
    case 1: return JoystickPosition::Up;
    case 2: return JoystickPosition::Down;
    case 3: return JoystickPosition::Left;
    case 4: return JoystickPosition::Right;
    default: return JoystickPosition::Center;
    }
}