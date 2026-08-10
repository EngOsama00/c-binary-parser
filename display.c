#include <stdio.h>

#include "display.h"
#include "types.h"

void displayDataTypes(void) {
    printf("\n||========================================||\n");
    printf("||        C DATA TYPE ANALYZER            ||\n");
    printf("||========================================||\n");

    printf("\nAvailable Data Types:\n\n");

    printf("Unsigned:\n");
    printf("  u8   u16   u32   u64\n");

    printf("\nSigned:\n");
    printf("  i8   i16   i32   i64\n");

    printf("\nFloating Point:\n");
    printf("  f32  f64\n");
}

void displaySelectedType(DataType type) {
    const DataTypeInfo* info = getDataTypeInfo(type);

    if (info == NULL) {
        printf("\nSelected Data Type: Invalid\n");
        return;
    }

    printf("\nSelected Data Type: %s\n", info->name);
    printf("Size           : %d bits\n", info->bits);

    if (info->isFloating)
        printf("Category       : Floating Point\n");
    else if (info->isUnsigned)
        printf("Category       : Unsigned Integer\n");
    else
        printf("Category       : Signed Integer\n");
}

void displayResultHeader(void) {
    printf("\n||========================================||\n");
    printf("||                 RESULT                 ||\n");
    printf("||========================================||\n");
}

void displayInvalidType(void) {
    printf("\n[ERROR] Invalid Data Type!\n");

    printf("Please choose one of:\n");
    printf("u8  u16  u32  u64\n");
    printf("i8  i16  i32  i64\n");
    printf("f32 f64\n");
}

void displayInvalidValue(DataType type) {
    printf("\n[ERROR] Invalid Value!\n");

    printf("The entered value is outside the valid range for ");

    switch (type) {
        case TYPE_U8:
            printf("u8 (0 to 255)");
            break;

        case TYPE_U16:
            printf("u16 (0 to 65535)");
            break;

        case TYPE_U32:
            printf("u32 (0 to 4294967295)");
            break;

        case TYPE_U64:
            printf("u64");
            break;

        case TYPE_I8:
            printf("i8 (-128 to 127)");
            break;

        case TYPE_I16:
            printf("i16 (-32768 to 32767)");
            break;

        case TYPE_I32:
            printf("i32 (-2147483648 to 2147483647)");
            break;

        case TYPE_I64:
            printf("i64");
            break;

        case TYPE_F32:
            printf("f32");
            break;

        case TYPE_F64:
            printf("f64");
            break;

        default:
            printf("unknown type");
            break;
    }

    printf(".\n");
}