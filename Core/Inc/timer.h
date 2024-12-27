//
// Created by Aleksandr on 24.06.2024.
//
#ifndef INTERRUPTMANAGMENT_TIMER_H
#define INTERRUPTMANAGMENT_TIMER_H
#include "irq_controller.h"

/*!@class Абстрактный Класс IrqController реализующий перенос таблицы векторов
 * прерываний в RAM и регистрации своих обработчиков прерываний
 */
class Timer1 : IrqController{
public:
    /*!
    * @brief Конструктор класса
    *
    * Используется для назначения своего обработчика
    * прерывания и инициализаци сомого таймера
    *
    * @param TIM_IRQ Номер обработчика прерывания который будет заменён
    */
    Timer1(uint8_t TIM_IRQ);
private:
    //Метод инициализации таймера и разрешения прерывания от него
    void initTim();
    //Свой обработчик прерывания
    void irqHandler() override;
};

#endif //INTERRUPTMANAGMENT_TIMER_H
