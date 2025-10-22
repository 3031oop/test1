#include <stdio.h>

int main(void){
    int N,i;
    double speed[100];
    double delta;
    int sudden_braking = 0;
    int sudden_acceleration = 0;

    printf("주행 로그 개수 N: ");
    scanf("%d",&N);

    for (i=0; i<N; i++){
        printf("속도 v(km/h): ");
        scanf("%lf",&speed[i]);
    }

    for (i=1; i<N; i++){
       delta = speed[i] - speed[i-1];
       if (delta >= 10) sudden_acceleration++;
       else if (delta <= -10) sudden_braking++;
    }

    printf("\n[결과]\n");
    printf("급가속 수: %d번\n", sudden_acceleration);
    printf("급제동 수: %d번\n", sudden_braking);

    
}