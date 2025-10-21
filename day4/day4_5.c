#include <stdio.h>

int main(void){
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score) / sizeof(score[0]);
    // sizeof(score)=20(5*4)byte
    // sizeof(score[0])=4(1*4)byte
    // count = 5 -> c는 byte 단위

    for (i =0; i<count; i++){
        scanf("%d", &score[i]);
    }

    for (i=0; i<count; i++){
        total += score[i];
    }
    avg = total / (double)count;

    for (i=0; i<count; i++){
        printf("%5d", score[i]);
    }
    printf("\n");

    printf("평균 : %.1lf\n",avg);

    return 0;
}