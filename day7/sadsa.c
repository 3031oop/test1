#include <stdio.h>

void print_ary(int *pa, int size);

int main(void){
    int ary1[5] = {10, 20, 30, 40, 50};
    int *pa = ary1;
    printf("%ld\n",sizeof(*pa));
    printf("%ld\n",sizeof(ary1)/sizeof(*pa));
    printf("%ld\n",sizeof(pa));
}