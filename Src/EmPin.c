#include "EmPin.h"

EmPin_t EmPin(GPIO_TypeDef* gpioX, uint16_t gpioPin)
{
	EmPin_t instance =
	{
		.gpioX = gpioX,
		.gpioPin = gpioPin
	};
	return instance;
}

void EmPin__write(EmPin_t* self, uint8_t state)
{
	EMPIN__WRITE(self, state);
}

uint8_t EmPin__read(EmPin_t* self)
{
	return EMPIN__READ_INPUT(self);
}

void EmPin__toggle(EmPin_t* self)
{
	EMPIN__TOGGLE(self);
}
