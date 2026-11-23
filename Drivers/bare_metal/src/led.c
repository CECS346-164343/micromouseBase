/**
  * @brief this is doxygen format
  * @author Aaron Oh
  * @param variable description
  * 
  */

 #include "led.h"

 void enable_GPIOA(void){
    //Enable clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 
    
    //PA5 mode bits are MODER[11:10], clear bits: MODER[1100_0000_0000] 0-F | F = [1111]
    GPIOA->MODER &= ~0xC00;

    // Set 01 = general-purpose output 
    GPIOA->MODER |= 0x400;

    // push-pull: OTYPER bit 5 = 0
    GPIO->OTYPER &= ~0x20;

    // low speed: OSPEEDR[11:10] = 00
    GPIO->OSPEEDR &= ~0xC00;

    //pull up/ pulldown resistor PUPDR[11:10] = 00
    GPIO->PUPDR &= ~0xC00;
 }

 void led_high(void){
    GPIOA->BSSR |= 0x00000020;
 }
 void led_low(void){
    GPIOA->BSSR |= 0x00200000;
 }