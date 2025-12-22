 /*
        things to consider adding
        - store ArrayList structs automatically, and just return pointers to them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array-list.h"

/*
typedef struct {
    void *ptr;
    unsigned int len;
} FatPointer;

FatPointer fatMalloc(unsigned int type_size, unsigned int length) {

    FatPointer fat_pointer;
    fat_pointer.len = length;
    fat_pointer.ptr = malloc(type_size * length);

    if (fat_pointer.ptr == NULL) {
        printf("\nallocation failed!");
    }

    return fat_pointer;
}
*/

unsigned int page_size = 4096;

/* what if we just returned a pointer to the arraylist so we don't have to
preface all our argument passes with `&`? */
ArrayList initArrayList(unsigned int type_size) {
    ArrayList list;
    list.items = malloc(page_size);
    list.len = 0;
    list.capacity  = page_size / type_size;
    list.type_size = type_size;

    return list;
}

void deinitArrayList(ArrayList *list) {
    free(list->items);

    /* do stuff to prevent you from accidentally trying
    to use an arraylist after it's been deinitialized? */
    list->capacity = 0;
    list->items = 0;
}

void appendToArrayList(ArrayList *list, void *value) {
    unsigned int type_size = list->type_size;

    if (list->len == list->capacity) {
        void *new_memory = malloc(type_size * list->capacity * 2);
        memcpy(new_memory, list->items, type_size * list->capacity);
        free(list->items);
        list->items = new_memory;
        list->capacity * 2;
    }

    unsigned char *new_index = (unsigned char *)list->items + type_size * list->len;
    memcpy(new_index, value, type_size);

    list->len ++;
}

void swapRemove(ArrayList *list, unsigned int index) {
    unsigned int type_size = list->type_size;

    unsigned char *element_to_remove = (unsigned char *)list->items + type_size * index;
    unsigned int new_len = list->len - 1;
    unsigned char *last_element = (unsigned char *)list->items + type_size * new_len;
    memcpy(element_to_remove, last_element, type_size);

    list->len = new_len;
}
