#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdint.h>
#include "types.h"

void printHex(uint64_t value);

void valueToBytes(uint64_t value, uint8_t bytes[], int byteCount);

void printBytesBinary(const uint8_t bytes[], int byteCount);

void printIntegerResult(DataType type, const char* input);

void printFloatResult(DataType type, const char* input);

#endif
