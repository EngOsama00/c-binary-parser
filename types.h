#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef enum {
    TYPE_U8,
    TYPE_U16,
    TYPE_U32,
    TYPE_U64,

    TYPE_I8,
    TYPE_I16,
    TYPE_I32,
    TYPE_I64,

    TYPE_F32,
    TYPE_F64,

    TYPE_INVALID
} DataType;

typedef struct
{
    DataType type;
    const char* name;
    int bits;
    int isUnsigned;
    int isFloating;
} DataTypeInfo;

const DataTypeInfo* getDataTypeInfo(DataType type);

#endif