#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversion.h"

void printHex(uint64_t value) {
    printf("0x%llX\n", (unsigned long long)value);
}

/*
 * Convert a value into an array of bytes.
 * Byte order used here is Little Endian:
 * B0 = least significant byte.
 */
void valueToBytes(uint64_t value, uint8_t bytes[], int byteCount) {
    if (bytes == NULL || byteCount <= 0 || byteCount > 8)
        return;

    for (int i = 0; i < byteCount; i++) {
        bytes[i] = (uint8_t)(value >> (i * 8));
    }
}

/*
 * Print Binary from the actual byte array.
 * The array itself can later be sent through UART, SPI, CAN, etc.
 */
void printBytesBinary(const uint8_t bytes[], int byteCount) {
    if (bytes == NULL || byteCount <= 0)
        return;

    for (int byte = 0; byte < byteCount; byte++) {
        if (byte == 0)
            printf("Binary    : ");
        else
            printf("            ");

        printf("B%d: ", byte);

        for (int bit = 7; bit >= 0; bit--) {
            uint8_t currentBit = (bytes[byte] >> bit) & 1U;
            printf("%u", currentBit);
        }

        printf("\n");
    }
}

void printIntegerResult(DataType type, const char* input) {
    uint8_t bytes[8];
    int byteCount = 0;

    switch (type) {
        case TYPE_U8: {
            uint8_t value = (uint8_t)strtoul(input, NULL, 10);
            byteCount = 1;

            printf("Decimal   : %" PRIu8 "\n", value);

            printf("Hex       : ");
            printHex(value);

            valueToBytes(value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_U16: {
            uint16_t value = (uint16_t)strtoul(input, NULL, 10);
            byteCount = 2;

            printf("Decimal   : %" PRIu16 "\n", value);

            printf("Hex       : ");
            printHex(value);

            valueToBytes(value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_U32: {
            uint32_t value = (uint32_t)strtoul(input, NULL, 10);
            byteCount = 4;

            printf("Decimal   : %" PRIu32 "\n", value);

            printf("Hex       : ");
            printHex(value);

            valueToBytes(value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_U64: {
            uint64_t value = (uint64_t)strtoull(input, NULL, 10);
            byteCount = 8;

            printf("Decimal   : %" PRIu64 "\n", value);

            printf("Hex       : ");
            printHex(value);

            valueToBytes(value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_I8: {
            int8_t value = (int8_t)strtol(input, NULL, 10);
            byteCount = 1;

            printf("Decimal   : %" PRId8 "\n", value);

            printf("Hex       : ");
            printHex((uint8_t)value);

            valueToBytes((uint8_t)value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_I16: {
            int16_t value = (int16_t)strtol(input, NULL, 10);
            byteCount = 2;

            printf("Decimal   : %" PRId16 "\n", value);

            printf("Hex       : ");
            printHex((uint16_t)value);

            valueToBytes((uint16_t)value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_I32: {
            int32_t value = (int32_t)strtol(input, NULL, 10);
            byteCount = 4;

            printf("Decimal   : %" PRId32 "\n", value);

            printf("Hex       : ");
            printHex((uint32_t)value);

            valueToBytes((uint32_t)value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        case TYPE_I64: {
            int64_t value = (int64_t)strtoll(input, NULL, 10);
            byteCount = 8;

            printf("Decimal   : %" PRId64 "\n", value);

            printf("Hex       : ");
            printHex((uint64_t)value);

            valueToBytes((uint64_t)value, bytes, byteCount);
            printBytesBinary(bytes, byteCount);

            break;
        }

        default:
            printf("[ERROR] Not an integer type!\n");
            break;
    }
}

void printFloatResult(DataType type, const char* input) {
    if (type == TYPE_F32) {
        float value = strtof(input, NULL);
        uint32_t bits;
        uint8_t bytes[4];

        memcpy(&bits, &value, sizeof(bits));

        printf("Decimal   : %.9g\n", value);
        printf("Hex       : 0x%08" PRIX32 "\n", bits);

        valueToBytes(bits, bytes, 4);
        printBytesBinary(bytes, 4);

    } else if (type == TYPE_F64) {
        double value = strtod(input, NULL);
        uint64_t bits;
        uint8_t bytes[8];

        memcpy(&bits, &value, sizeof(bits));

        printf("Decimal   : %.17g\n", value);
        printf("Hex       : 0x%016" PRIX64 "\n", bits);

        valueToBytes(bits, bytes, 8);
        printBytesBinary(bytes, 8);
    }
}