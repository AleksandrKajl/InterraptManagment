//
// Created by Aleksandr on 24.06.2024.
//
#include "timer.h"
#include "stm32f1xx_hal.h"

Timer1::Timer1(uint8_t TIM_IRQ) : IrqController(this) {
    //Назначаем свой обработчик прерывания
    this->attachHandler(TIM_IRQ);
    //Инициализируем таймер
    initTim();
}

void Timer1::irqHandler() {
    //Моргаем светодиодом
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    //Сброс флага прерывания
    TIM1->SR &= ~TIM_SR_UIF;
}

void Timer1::initTim() {
    //Разрешаем тактирование
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    //Задаём тактирование от шины APB
    TIM1->SMCR &= ~TIM_SMCR_SMS;
    //Режим работы таймера
    TIM1->CR1 = TIM_CR1_CEN;
    //Регистр пределитиля и перезагрузки
    TIM1->PSC = 719;
    TIM1->ARR = 24999;
    //Разрешаем прерывание
    TIM1->DIER |= TIM_DIER_UIE;
    //B регистре контроллера прерываний
    NVIC_EnableIRQ(TIM1_UP_IRQn);
}
