//
// Created by Aleksandr on 26.06.2024.
//

#ifndef INTERRUPTMANAGMENT_STRUCTURES_H
#define INTERRUPTMANAGMENT_STRUCTURES_H
/*!
 * @brief Класс перечеслений хранящий в себе
 * номера обработчиков прерываний
 */

enum class Isr_Vector
{
    INITIAL_SP = 0,
    RESET_EX,
    NMI_EX,
    HARDFAULT_EX,
    MMU_EX,
    BUS_EX,
    USAGE_EX,
    SVCALL_EX = 11,
    PENDSV_EX = 14,
    SYSTICK_EX,
    WWDG_EX,
    PVD_EX,
    TAMPER_EX,
    RTC_EX,
    FLASH_EX,
    RCC_EX,
    EXTI0_EX,
    EXTI1_EX,
    EXTI2_EX,
    EXTI3_EX,
    EXTI4_EX,
    DMA1_Channel1_EX,
    DMA1_Channel2_EX,
    DMA1_Channel3_EX,
    DMA1_Channel4_EX,
    DMA1_Channel5_EX,
    DMA1_Channel6_EX,
    DMA1_Channel7_EX,
    ADC1_2_EX,
    USB_HP_CAN1_TX_EX,
    USB_LP_CAN1_RX0_EX,
    CAN1_RX1_EX,
    CAN1_SCE_EX,
    EXTI9_5_EX,
    TIM1_BRK_EX,
    TIM1_UP_EX,
    TIM1_TRG_COM_EX,
    TIM1_CC_EX,
    TIM2_EX,
    TIM3_EX,
    TIM4_EX,
    I2C1_EV_EX,
    I2C1_ER_EX,
    I2C2_EV_EX,
    I2C2_ER_EX,
    SPI1_EX,
    SPI2_EX,
    USART1_EX,
    USART2_EX,
    USART3_EX,
    EXTI15_10_EX,
    RTC_Alarm_EX,
    USBWakeUp_EX,
};

#endif //INTERRUPTMANAGMENT_STRUCTURES_H
