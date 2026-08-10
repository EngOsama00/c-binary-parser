#include <stddef.h>
#include "types.h"

static const DataTypeInfo dataTypes[] =
{
    { TYPE_U8,  "u8",  8,  1, 0 },
    { TYPE_U16, "u16", 16,  1, 0 },
    { TYPE_U32, "u32", 32,  1, 0 },
    { TYPE_U64, "u64", 64,  1, 0 },

    { TYPE_I8,  "i8",  8,  0, 0 },
    { TYPE_I16, "i16", 16,  0, 0 },
    { TYPE_I32, "i32", 32,  0, 0 },
    { TYPE_I64, "i64", 64,  0, 0 },

    { TYPE_F32, "f32", 32,  0, 1 },
    { TYPE_F64, "f64", 64,  0, 1 }
};

const DataTypeInfo *getDataTypeInfo(DataType type)
{
    if (type < TYPE_U8 || type > TYPE_F64)
        return NULL;

    return &dataTypes[type];
}