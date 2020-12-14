#pragma once

//Zスライダ
//専用クラス
class SliderZ : public SliderMechanism
{
public:
    //SliderZ(DcMotor* dcMotor, Encoder* encoder, Potentio);
    ~SliderZ();
    //一定PWMで動作(+で上昇)
    //[%]
    void constPwmMove(double pwm);
    //一定速度で上昇
    //vel[mm/s]
    void constVelMove(double vel);
    //滞在
    //下からpos[mm]
    void keepPos(double pos);

private:
};