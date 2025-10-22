#include <stdio.h>

int main(void){
    int N,i;
    double battery[100];
    int warning = 0; // 0:OFF, 1:ON

    printf("데이터 개수 N: ");
    scanf("%d",&N);

    for (i=0; i<N; i++){
        printf("배터리 잔량 로그(%%): ");
        scanf("%lf",&battery[i]);
        if (warning == 0 && battery[i] <= 30) {
            warning = 1;
            printf("경고 상태 : ON\n");
        }
        else if (warning == 1 && battery[i] >= 35) {
            warning = 0;
            printf("경고 상태 : OFF\n");
        }
    }
}