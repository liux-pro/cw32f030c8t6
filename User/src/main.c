/******************************************************************************
 * Include files
 ******************************************************************************/
#include "main.h"
#include "cw32f030_gpio.h"
#include "cw32f030_rcc.h"
#include "cw32f030_systick.h"

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

#define LED_GPIO_PORT CW_GPIOC
#define LED_GPIO_PINS GPIO_PIN_13

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/******************************************************************************
 * Local variable definitions ('static')                                      *
 ******************************************************************************/

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/


/**
 ******************************************************************************
 ** \brief  Main function of project
 **
 ** \return uint32_t return value, if needed
 **
 ** 基于官方示例,制作本本模板，带所有外设驱动；整个项目编码转为utf-8。
 ** cw32f030_iwdt.c 编译报错，不过我用不到，不去管他了
 ** Starup里面是启动文件吧，不太懂，不要动就好
 ** Libraries里面是外设驱动库文件，用到什么就include对应的头文件，不要动
 ** User里面是代码，main.c里写程序。interrupt_cw32f030.c里面是所有的中断函数
 ** 示例电灯程序，PC13的LED闪烁。无需外部晶振。
 ** 下载器为daplink，无需额外设置，直接点下载应该就能下。
 **
 ******************************************************************************/
int32_t main(void)
{
	
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_HSI_Enable(RCC_HSIOSC_DIV6);
    __RCC_GPIOC_CLK_ENABLE();

    GPIO_InitStruct.IT = GPIO_IT_NONE;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pins = LED_GPIO_PINS;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

    while (1)
    {
        GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PINS);
        delay1ms(800);
    }
    
}


/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

