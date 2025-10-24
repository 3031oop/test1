#include <stdio.h>

void swap(int *pa, int *pb);

// int main(void){
//     int a = 10, b = 20;

//     swap(&a,&b);
//     printf("a:%d, b:%d\n", a, b);

//     return 0;
// }

// void swap(int *pa, int *pb){
//     int temp;
//     temp = *pb;
//     *pa = *pb;
//     *pb = temp;
// }


int main(void){
    int a = 10, b = 20;
    int *pa = &a;
    int *pb = &b;
    
    swap(pa, pb);
    printf("a:%d, b:%d\n", *pa, *pb);

    return 0;
}

void swap(int *pa, int *pb){
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}