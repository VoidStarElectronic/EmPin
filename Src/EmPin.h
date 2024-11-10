#ifndef EMPIN_H_
#define EMPIN_H_

#include "stm32xxxx_hal.h"

#define EMPIN__SET(SELF)      		  do{(SELF)->gpioX->BSRR = (SELF)->gpioPin;}while(0)
#define EMPIN__RESET(SELF)   		  do{(SELF)->gpioX->BRR  = (SELF)->gpioPin;}while(0)
#define EMPIN__TOGGLE(SELF)  		  do{(SELF)->gpioX->ODR ^= (SELF)->gpioPin;}while(0)
#define EMPIN__WRITE(SELF, STATE)     do{(SELF)->gpioX->BSRR = ((STATE) == 0) ? ((SELF)->gpioPin<<16) : (SELF)->gpioPin;}while(0)
#define EMPIN__READ_INPUT(SELF)       (((SELF)->gpioX->IDR & (SELF)->gpioPin) != 0)
#define EMPIN__READ_OUTPUT(SELF)      (((SELF)->gpioX->ODR & (SELF)->gpioPin) != 0)

typedef struct
{
	GPIO_TypeDef* gpioX;
	uint32_t 	  gpioPin;
}EmPin_t;

EmPin_t EmPin(GPIO_TypeDef* gpioX, uint16_t gpioPin);
void 	EmPin__write(EmPin_t* self, uint8_t state);
uint8_t EmPin__read(EmPin_t* self);
void 	EmPin__toggle(EmPin_t* self);

#endif /* EMPIN_H_ */
