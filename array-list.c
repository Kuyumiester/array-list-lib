/*
    lists of this library can support up to 65,536 elements
*/

 /*
        things to consider
    it would probably be more performant to pass the ArrayList to functions by value
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "array-list.h"

uint32_t page_size = 4096;

ArrayList arrayListInit(uint16_t type_size) {
    ArrayList list;
    list.items = malloc(page_size);
    list.len = 0;
    list.capacity = 0;
    list.type_size = type_size;

    return list;
}

void arrayListDeinit(ArrayList *list) {
    free(list->items);

    /* do stuff to prevent you from accidentally trying
    to use an arraylist after it's been deinitialized */
    memset(list, 0, 16);
}

void growIfFull(ArrayList *list) {
    ArrayList list_v = *list;
    if (list_v.len * list_v.type_size == page_size << list_v.capacity) {
        void *new_memory = malloc(page_size << (list_v.capacity + 1));
        memcpy(new_memory, list_v.items, page_size << list_v.capacity);
        free(list_v.items);
        list->items = new_memory;
        list->capacity++;
    }
}

/*
    adds an element to the list.
    O(1)
*/
void arrayListAppend(ArrayList *list, void *value) {
    uint16_t type_size;
    uint8_t *new_index;
    type_size = list->type_size;

    growIfFull(list);

    new_index = (uint8_t *)list->items + type_size * list->len;
    memcpy(new_index, value, type_size);

    list->len ++;
}

/*
    adds an element into the list at the given index after moving succeeding elements forward
    O(n)
*/
void arrayListInsert(ArrayList *list, void *value, uint16_t index) {
    /* TODO */
}

/*
    removes an element from the list.
    does not retain order.
    O(1)
*/
void arrayListRemove(ArrayList *list, uint16_t index) {
    uint16_t type_size = list->type_size;
    uint8_t *element_to_remove = (uint8_t *)list->items + type_size * index;
    uint16_t new_len = list->len - 1;

    uint8_t *last_element = (uint8_t *)list->items + type_size * new_len;
    memcpy(element_to_remove, last_element, type_size);

    list->len = new_len;
}

/*
    removes an element from the list.
    retains order.
    O(n)
*/
void arrayListRemoveRetainOrder(ArrayList *list, uint16_t index) {
    uint16_t type_size = list->type_size;
    uint8_t *element_to_remove = (uint8_t *)list->items + type_size * index;
    uint16_t new_len = list->len - 1;

    memcpy(element_to_remove, element_to_remove + type_size, type_size * (new_len - index));

    list->len = new_len;
}