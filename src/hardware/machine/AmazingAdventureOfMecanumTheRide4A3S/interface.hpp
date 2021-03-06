#pragma once
#include "../../circuit/F405ControlBoard.hpp"
#include "../parts/interface/led.hpp"
#include "../parts/interface/button.hpp"
#include "../parts/interface/buzzer.hpp"
#include "../parts/interface/user_encoder.hpp"
#include "../parts/interface/clcd.hpp"

#define LED_NUM 4
#define BUTTON_NUM 4

namespace interface
{
void setup(void);
//void interrupt_1ms(void);

extern Led led[LED_NUM];
extern Button button[BUTTON_NUM];
extern Buzzer buzzer;
//UserEncoder userEncoder;
//CharacterLcd clcd;
//Serial* pc;
//Controller* sixaxis3;
}//namespace
