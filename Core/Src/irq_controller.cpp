//
// Created by Aleksandr on 24.06.2024.
//
#include "irq_controller.h"
#include "main.h"

#define VECTOR_TABLE_SIZE 68

//Статические переменные
IrqController* IrqController::obj = nullptr;
bool IrqController::isRemapVecTable = false;

//Массив для таблицы векторов прерываний указывающий на начало RAM
volatile uint32_t __attribute__((section(".ram_vector,\"aw\",%nobits @"))) ram_vector[VECTOR_TABLE_SIZE];
//Вектора прерываний из startup
extern volatile uint32_t g_pfnVectors[VECTOR_TABLE_SIZE];

//Метод замены обработчика прерывания
void IrqController::attachHandler(uint8_t IRQ) {
    remapVecTable();
    ram_vector[IRQ] = (uint32_t)handler;
}

/*Статичный метод обработчика прерываний
* который вызывает обработчик прерываний дочернего объекта
* указатель на который был получен в конструкторе класса
*/
void IrqController::handler() {
    obj->irqHandler();
}

//Перенос тавблицы векторов прерываний в RAM
void IrqController::remapVecTable() {
    //Если Вектора прерываний в RAM
    if(isRemapVecTable){
       return;
    }
    else{
        isRemapVecTable = true;
    }
    //Копируем таблицу векторов
    for (uint8_t i = 0; i < VECTOR_TABLE_SIZE; i++) {
        ram_vector[i] = g_pfnVectors[i];
    }

    __disable_irq();
    SCB->VTOR = (uint32_t)ram_vector;           //Загрузка нового адреса таблицы векторов прерываний
    __DSB (); //Синхронизация обращений к памяти
    __enable_irq();
    __ISB();  //Синхронизация выполнения комманд
}


