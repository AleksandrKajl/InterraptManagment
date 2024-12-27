//
// Created by Aleksandr on 24.06.2024.
//
#ifndef INTERRUPTMANAGMENT_IRQ_CONTROLLER_H
#define INTERRUPTMANAGMENT_IRQ_CONTROLLER_H
#include <cstdint>

/*!@class Абстрактный Класс IrqController реализующий перенос таблицы векторов
 * прерываний в RAM и регистрации своих обработчиков прерываний
 */
class IrqController{
public:
    /*!
    * @brief Конструктор класса
    *
    * Используется для обязательной инициализации
    * статической переменной указателем на объект класса наследника
    * который в обязательном порядке реализует обработчик прерывания
    *
    * @param child Указатель на объект класса наследника
    */
    IrqController(IrqController* child){ obj = child;}
    /*!
    * @brief Метод добавления своего обработчика прерывания
    * в таблицу векторов прерываний
    *
    * @param IRQ Номер заменяемого обработчика прерывания
    */
    void attachHandler(uint8_t IRQ);

private:
    //Статичный указатель на объект класса наследника
    static IrqController* obj;
    //Статичная переменная для определения того что ремап таблицы в RAM был выполнен
    static bool isRemapVecTable;

private:
    //Метод переноса таблицы векторов прерываний в RAM
    void remapVecTable();
    //Обёртка для своего обрботчика прерывания
    static void handler();
    /*Чисто виртуальный метод для обязательной реализация обработчика
     *прерывания в классе наследнике*/
    virtual void irqHandler() = 0;
};

#endif //INTERRUPTMANAGMENT_IRQ_CONTROLLER_H
