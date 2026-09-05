/*
    compile and run with
    `gcc example-usage.c array-list.c -o "example-program"; ./example-program`
*/

#include "array-list.h"
#include "stdio.h"

int main(void) {
    ArrayList list;
    int value;
    int retrieved_value;
    int i;

    list = arrayListInit(sizeof (int)); /* { } */

    value = 9;
    arrayListAppend(&list, &value); /* { 9 } */

    #define integers ((int *)list.items)
    retrieved_value = integers[0];

    arrayListRemove(&list, 0); /* { } */

    /* use lots of memory (64 MiB) */
    for (i = 0; i < 10000000; i++) {
        arrayListAppend(&list, &i);
    }
    printf("additional allocations: %d\n", list.capacity);

    arrayListDeinit(&list);

    return 0;
}