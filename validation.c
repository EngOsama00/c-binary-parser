#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#include "validation.h"

static int validateUnsigned(const char* input, uint64_t max) {
    char* end;
    unsigned long long value;

    errno = 0;

    value = strtoull(input, &end, 10);

    if (*end != '\0')
        return 0;

    if (errno == ERANGE)
        return 0;

    if (value > max)
        return 0;

    return 1;
}

static int validateSigned(const char* input, int64_t min, int64_t max) {
    char* end;
    long long value;

    errno = 0;

    value = strtoll(input, &end, 10);

    if (*end != '\0')
        return 0;

    if (errno == ERANGE)
        return 0;

    if (value < min || value > max)
        return 0;

    return 1;
}

int validateValue(DataType type, const char* input) {
    switch (type) {
        case TYPE_U8:
            return validateUnsigned(input, UINT8_MAX);

        case TYPE_U16:
            return validateUnsigned(input, UINT16_MAX);

        case TYPE_U32:
            return validateUnsigned(input, UINT32_MAX);

        case TYPE_U64:
            return validateUnsigned(input, UINT64_MAX);

        case TYPE_I8:
            return validateSigned(input, INT8_MIN, INT8_MAX);

        case TYPE_I16:
            return validateSigned(input, INT16_MIN, INT16_MAX);

        case TYPE_I32:
            return validateSigned(input, INT32_MIN, INT32_MAX);

        case TYPE_I64:
            return validateSigned(input, INT64_MIN, INT64_MAX);

        case TYPE_F32:
        case TYPE_F64: {
            char* end;

            errno = 0;

            strtod(input, &end);

            if (*end != '\0')
                return 0;

            if (errno == ERANGE)
                return 0;

            return 1;
        }

        default:
            return 0;
    }
}