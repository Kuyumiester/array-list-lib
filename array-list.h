#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <stdint.h>

typedef struct {
    void *items;
    uint32_t len;
    uint16_t type_size;
    uint8_t capacity; /* the log2 of the number of allocated pages */
} ArrayList;

ArrayList arrayListInit(uint16_t type_size);
void arrayListDeinit(ArrayList *list);
void arrayListAppend(ArrayList *list, void *value);
void arrayListRemove(ArrayList *list, uint16_t index);
void arrayListRemoveRetainOrder(ArrayList *list, uint16_t index);

#endif /* ARRAY_LIST_H_ */