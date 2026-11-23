#pragma once

#ifdef __cplusplus 
extern "C" {
#endif

#include "main.h"
#include "stm32f4xx.h"

 void enable_GPIOA(void);
 void led_high(void);
 void led_low(void);

#ifdef __cplusplus
}
#endif