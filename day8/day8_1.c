// 예제 12-9 strncpy 함수를 사용한 문자열 복사
#include <stdio.h>
#include <string.h>

int main(void){

    char str[20] = "mango tree";
   
    strncpy(str, "apple-pie", 5);

    // mango apple
    // strncpy(str+6, "apple-pie", 5);
    
    printf("바뀐 문자열 : %s\n", str);

    return 0;
}