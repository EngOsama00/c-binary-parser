#include <stdio.h>
#include <string.h>

#include "input.h"

DataType getDataType(void) {
    char input[10];

    printf("\nEnter Data Type: ");

    if (fgets(input, sizeof(input), stdin) == NULL)
        return TYPE_INVALID;

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "u8") == 0)
        return TYPE_U8;

    if (strcmp(input, "u16") == 0)
        return TYPE_U16;

    if (strcmp(input, "u32") == 0)
        return TYPE_U32;

    if (strcmp(input, "u64") == 0)
        return TYPE_U64;

    if (strcmp(input, "i8") == 0)
        return TYPE_I8;

    if (strcmp(input, "i16") == 0)
        return TYPE_I16;

    if (strcmp(input, "i32") == 0)
        return TYPE_I32;

    if (strcmp(input, "i64") == 0)
        return TYPE_I64;

    if (strcmp(input, "f32") == 0)
        return TYPE_F32;

    if (strcmp(input, "f64") == 0)
        return TYPE_F64;

    return TYPE_INVALID;
}

int getInput(char* buffer, int size) {
    if (buffer == NULL || size <= 1)
        return 0;

    printf("Enter Value: ");

    if (fgets(buffer, size, stdin) == NULL)
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';

    if (buffer[0] == '\0')
        return 0;

    return 1;
}