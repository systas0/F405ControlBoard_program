#pragma once
#include "stm32f405xx.h"
#include <stdint.h>

namespace iwdg
{
//!     LSIからのクロック供給なのでメインクロックに障害があってもアクティブなまま
//!     精度はそこまで高くないので注意

//:**********************************************************************
//!
//! @param in
//!     division:   IWDGによるリセットまでの時間[us](125~1000)
//! @details
//!     分周によるタイムアウト時間
//!                 |最小[ms]   |最大[ms]
//!         /4      |   0.125   |     512
//!         /8      |   0.25    |    1024
//!         /16     |   0.5     |    2048
//!         /32     |   1       |    4096
//!         /64     |   2       |    8192
//!         /128    |   4       |   16384
//!         /256    |   8       |   32768
//!
//:**********************************************************************
void setup_us(uint16_t division);

//:**********************************************************************
//!
//! @param in
//!     division:   IWDGによるリセットまでの時間[ms](1~32768)
//! @details
//!     分周によるタイムアウト時間
//!                 |最小[ms]   |最大[ms]
//!         /4      |   0.125   |     512
//!         /8      |   0.25    |    1024
//!         /16     |   0.5     |    2048
//!         /32     |   1       |    4096
//!         /64     |   2       |    8192
//!         /128    |   4       |   16384
//!         /256    |   8       |   32768
//!
//:**********************************************************************
void setup_ms(uint16_t division);

//:**********************************************************************
//!
//! @brief  IWDGカウンタの再ロード
//!     
//:**********************************************************************
void reset(void);

//:**********************************************************************
//!
//! @brief  IWDGカウントダウンスタート
//!     
//:**********************************************************************
void start(void);

}//namespace
