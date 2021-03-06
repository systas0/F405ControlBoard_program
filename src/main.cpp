#include "./hardware/circuit/F405ControlBoard.hpp"
//#include "./hardware/circuit/function/delay.hpp"
#include "./hardware/machine/AmazingAdventureOfMecanumTheRide4A3S/interface.hpp"
#include <stddef.h>
//#include "machine.hpp"

//TODO: 割り込み処理のRTOS化
//THINK: タイムスタンプほしいな

using namespace interface;

int main(void)
{
    //ペリフェラルセットアップ
    F405ControlBoard::getInstance()->setup();
    //F405ControlBoard::getInstance()->setupInterface();

    interface::setup();

    led[1].write(1);
    ////delay_ms(1000);
    //F405ControlBoard::getInstance()->delay_ms(1000);
    buzzer.beep(1000);
    led[1].write(0);

    //sixaxis3 = new Sixaxis(&usart4);
    //mpu6050 = new Gyro(&usart3, IMU_TYPE_MPU6050);

    while(1)
    {
        F405ControlBoard::getInstance()->cycle();

        if(button[0].read()) led[0].write(1);
        else led[0].write(0);
        if(button[1].read()) led[1].write(1);
        else led[1].write(0);

        //目標値反映
        //can送信、local反映
        //actuator::update();

    }
}

//! 1ms割り込み
void interrupt_1ms(void)
{
    F405ControlBoard::getInstance()->interrupt_1ms();

    static int cnt1 = 0;
    if(++cnt1 >= 100)
    {
        cnt1 = 0;
        led[2].toggle();
    }
}

//! 10ms割り込み
void interrupt_10ms(void)
{
    //sensor::update();

    //Machine::getInstance()->update();

    static int cnt2 = 0;
    if(++cnt2 >= 10)
    {
        cnt2 = 0;
        led[3].toggle();
    }

    //目標値変更
    //制御こ↑こ↓

}
