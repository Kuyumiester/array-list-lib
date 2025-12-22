#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

typedef struct {
    void *items;
    unsigned int len;
    unsigned int capacity;
    unsigned int type_size;
} ArrayList;

ArrayList initArrayList(unsigned int type_size);

void deinitArrayList(ArrayList *list);

void appendToArrayList(ArrayList *list, void *value);

void swapRemove(ArrayList *list, unsigned int index);

#endif /* ARRAY_LIST_H_ */