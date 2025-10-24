//포인터를 이용한 변수 값 변경
#include <stdio.h>

int main(void){
    int a = 10;
    int *pa;

    pa = &a;
    printf("포인터 사용 전: %d\n", *pa);
    *pa = 20;
    printf("포인터 사용 후: %d\n", *pa);
    
    return 0;

}

