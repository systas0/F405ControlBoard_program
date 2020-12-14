#pragma once
#include "../parts.hpp"
#include "GPIO.hpp"
#include <stdint.h>

class Buzzer
{
public:
    Buzzer(PartsType partsType = LOCAL, GPIO* gpio);
    ~Buzzer();
    void setupGPIO(GPIO* gpio);
    void beep(uint16_t beepTime);

private:
    PartsType m_partsType;

    //LOCAL
    GPIO* m_gpio;   //器のみ。delete禁止

    uint16_t m_beepTime;    //[ms]

    //CAN
    //ビープ時間送信？
};