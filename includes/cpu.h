#ifndef CPU_H
#define CPU_H

#define JVM_MAGIC 0xCAFEBABE

typedef struct ConstPool {
    uint8_t tag;
    uint16_t name_index;
    uint16_t class_index;
    uint16_t name_type_index;
    uint16_t string_index;
    uint16_t desc_index;
    char *string;
} ConstPool;

typedef struct Attribute {
    char* name;
    uint8_t *data;
} Attribute;

typedef struct Field {
    uint16_t flags;
    char *name;
    char *descriptor;
    Attribute *attributes;
} Field;

typedef struct Class {
    struct ConstPool const_pool;
    char *name;
    char *super;
    uint16_t flags;
    char *interfaces;
    Field *fields;
    Field *methods;
    Attribute *attributes;
} Class;

#endif
