/*
    compile and run with
    `gcc example-usage.c array-list.c -o "example-program"; ./example-program`
*/

#include "array-list.h"

int main() {
    ArrayList list = initArrayList(sizeof (int)); /* { } */

    int value = 9;
    appendToArrayList(&list, &value); /* { 9 } */

    #define integers ((int *)list.items)
    int retrieved_value = integers[0];

    swapRemove(&list, 0); /* { } */

    deinitArrayList(&list);

    return 0;
}