#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>     
#include <stdint.h>     
#include <string.h>     
 

#define  BUFFER_MAX 4
#define  DIRECTION_MAX 35 
#define VALUE_MAX 30
#define IN 0
#define OUT 1
#define HIGH 1
#define LOW 0

int32_t GPIOExport(int32_t pin_);
int32_t GPIODirection(int32_t pin_, int32_t dir_);
int32_t GPIOWrite(int32_t pin_, int32_t value_);

#endif
