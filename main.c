#include <stdio.h>

#include "conversion.h"
#include "display.h"
#include "input.h"
#include "types.h"
#include "validation.h"

int main(void) {
    DataType type;
    char input[100];

    displayDataTypes();

    type = getDataType();

    if (type == TYPE_INVALID) {
        displayInvalidType();
        return 1;
    }

    displaySelectedType(type);

    if (!getInput(input, sizeof(input))) {
        printf("\n[ERROR] Invalid Input!\n");
        return 1;
    }

    if (!validateValue(type, input)) {
        displayInvalidValue(type);
        return 1;
    }

    displayResultHeader();

    if (type >= TYPE_U8 && type <= TYPE_I64) {
        printIntegerResult(type, input);
    } 
    else if (type == TYPE_F32 || type == TYPE_F64) {
        printFloatResult(type, input);
    }
     else {
        printf("[ERROR] Unknown Data Type!\n");
        return 1;
    }

    printf("\n||========================================||\n");
    printf("||             PROGRAM END                ||\n");
    printf("||========================================||\n");

    return 0;
}