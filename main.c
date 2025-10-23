#include "stdint.h"

#define PERIPHERAL_BLOCK2_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BLOCK2_BASE + 0x20000U)
#define GPIOA_BASE (AHB1_BASE + 0x0U)
#define RCC_BASE (AHB1_BASE + 0x3800U)

/* HAVE REGISTER VALUES BE VOLATILE */
//Used for reintializing peripherals
#define RCC_AHB1ENR_OFFSET (0x30U)
#define RCC_AHB1ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_GPIOAEN (0x00U)

/* PORT A PIN 4*/
#define GPIO_MODER_OFFSET (0x00U)
#define GPIOA_MODER ((volatile uint32_t*) (GPIOA_BASE + GPIO_MODER_OFFSET))
#define GPIO_MODER_MODER5 (10U)
#define GPIO_ODR_OFFSET (0x14U)
/* Set value of register */
#define GPIOA_ODR ((volatile uint32_t*) (GPIOA_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 5

void SystemInit(void) {}


int main(void) {
    //enable clock for IO Port A
    *RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN);

    //Perform 2 dummy reads to ensure data buffer is clear
    volatile uint32_t dummy;
    dummy = *(RCC_AHB1ENR);
    dummy = *(RCC_AHB1ENR);

    *GPIOA_MODER |= (1 << GPIO_MODER_MODER5);
    
    while(1) {
        *GPIOA_ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 1000000; i++);
    }
    return 0;
}