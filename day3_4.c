#include <stdio.h>

int main(void){
    int i,j;
    int k=5;

    for (i=0; i<5; i++){
        for (j=5; j-i>0; j--){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}