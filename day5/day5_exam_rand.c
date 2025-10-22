// 1) rand() 적용
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int N,i;
    double speed[1000];
    double delta;
    int sudden_braking = 0;
    int sudden_acceleration = 0;

    printf("주행 로그 개수 N: ");
    scanf("%d",&N);

    
    srand(time(NULL)); // 랜덤 초기화
    for (i=0; i<N; i++){
        
        speed[i] = rand() %100; // 0 ~ 99
        //printf("%.lf\n", speed[i]);
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