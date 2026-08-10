#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdint.h>
#include "types.h"

void printHex(uint64_t value);

void printBinary(uint64_t value, int bits);

void printIntegerResult(DataType type, const char* input);

void printFloatResult(DataType type, const char* input);

#endif