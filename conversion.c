#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conversion.h"

void printHex(uint64_t value) {
    printf("0x%llX\n", (unsigned long long)value);
}

void printBinary(uint64_t value, int bits) {
    int byteCount = bits / 8;

    for (int byte = 0; byte < byteCount; byte++) {
        if (byte == 0)
            printf("Binary    : ");
        else
            printf("            ");

        printf("B%d: ", byte);

        for (int bit = 7; bit >= 0; bit--) {
            int position = (byte * 8) + bit;

            uint64_t currentBit = (value >> position) & 1ULL;

            printf("%llu", (unsigned long long)currentBit);
        }

        printf("\n");
    }
}
void printIntegerResult(DataType type, const char* input) {
    switch (type) {
        case TYPE_U8: {
            uint8_t value = (uint8_t)strtoul(input, NULL, 10);

            printf("Decimal   : %" PRIu8 "\n", value);

            printf("Hex       : ");
            printHex(value);

            printBinary(value, 8);

            break;
        }

        case TYPE_U16: {
            uint16_t value = (uint16_t)strtoul(input, NULL, 10);

            printf("Decimal   : %" PRIu16 "\n", value);

            printf("Hex       : ");
            printHex(value);

            printBinary(value, 16);

            break;
        }

        case TYPE_U32: {
            uint32_t value = (uint32_t)strtoul(input, NULL, 10);

            printf("Decimal   : %" PRIu32 "\n", value);

            printf("Hex       : ");
            printHex(value);

            printBinary(value, 32);

            break;
        }

        case TYPE_U64: {
            uint64_t value = (uint64_t)strtoull(input, NULL, 10);

            printf("Decimal   : %" PRIu64 "\n", value);

            printf("Hex       : ");
            printHex(value);

            printBinary(value, 64);

            break;
        }

        case TYPE_I8: {
            int8_t value = (int8_t)strtol(input, NULL, 10);

            printf("Decimal   : %" PRId8 "\n", value);

            printf("Hex       : ");
            printHex((uint8_t)value);

            printBinary((uint8_t)value, 8);

            break;
        }

        case TYPE_I16: {
            int16_t value = (int16_t)strtol(input, NULL, 10);

            printf("Decimal   : %" PRId16 "\n", value);

            printf("Hex       : ");
            printHex((uint16_t)value);

            printBinary((uint16_t)value, 16);

            break;
        }

        case TYPE_I32: {
            int32_t value = (int32_t)strtol(input, NULL, 10);

            printf("Decimal   : %" PRId32 "\n", value);

            printf("Hex       : ");
            printHex((uint32_t)value);

            printBinary((uint32_t)value, 32);

            break;
        }

        case TYPE_I64: {
            int64_t value = (int64_t)strtoll(input, NULL, 10);

            printf("Decimal   : %" PRId64 "\n", value);

            printf("Hex       : ");
            printHex((uint64_t)value);

            printBinary((uint64_t)value, 64);

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

        memcpy(&bits, &value, sizeof(bits));

        printf("Decimal   : %.9g\n", value);

        printf("Hex       : 0x%08" PRIX32 "\n", bits);

        printBinary(bits, 32);
    } else if (type == TYPE_F64) {
        double value = strtod(input, NULL);

        uint64_t bits;

        memcpy(&bits, &value, sizeof(bits));

        printf("Decimal   : %.17g\n", value);

        printf("Hex       : 0x%016" PRIX64 "\n", bits);

        printBinary(bits, 64);
    }
}