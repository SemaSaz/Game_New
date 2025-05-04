#ifndef JOYSTICKHANDLER_H
#define JOYSTICKHANDLER_H

#include <Arduino.h>

enum class JoystickPosition {
    Center,
    Up,
    Down,
    Left,
    Right
};


String joystickPositionToString(JoystickPosition pos);

class JoystickHandler {
public:
    JoystickHandler();
    
    virtual JoystickPosition pollJoystick();

protected:
};

#endif
