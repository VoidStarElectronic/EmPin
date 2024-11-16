# EmPin
  Stm32 Pin Driver 
 
### Example :
```c
#include "main.h"
#include "gpio.h"
#include "EmPin.h"

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  EmPin_t button = EmPin(BUTTON_GPIO_Port, BUTTON_Pin);
  EmPin_t ledRed = EmPin(LED_RED_GPIO_Port, LED_RED_Pin);

  while(1)
  {
    EmPin__write(&ledRed, !EmPin__read(&button));
  }
}
```
