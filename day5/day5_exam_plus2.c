// 2) 변화량이 10이상 증가하지 않도록 rand 범위 제한
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int N,i;
    double speed[10000];
    double delta;
    double random;
    int sudden_braking = 0;
    int sudden_acceleration = 0;
    
    printf("주행 로그 개수 N: ");
    scanf("%d",&N);

    
    srand(time(NULL)); // 랜덤 초기화
    speed[0] = rand() %100;
    printf("%.lf\n", speed[0]);

    for (i=1; i<N; i++){
        // 1. 변화량 먼저 정하기
        // rand () % 19 -> 0 ~ 18 사이의 난수
        // (rand () % 19) -9 -> -9 ~ 9 사이의 난수
        delta = (rand() % 19 )-9 ;

        // 2. 새 속도 계산
        speed[i] = speed[i-1] + delta;

        // 3. 속도가 범위를 벗어나지 않도록 보정(0~100) 사이
        if (speed[i] < 0) speed[i] = 0;
        if (speed[i] > 99) speed[i] = 99;
        

    }

    // 변화량 10이하인지 확인
    for (i=1; i<N; i++){
    delta = speed[i] - speed[i-1];
    if (delta >= 10) sudden_acceleration++;
    else if (delta <= -10) sudden_braking++;
    }

    printf("\n[결과]\n");
    printf("급가속 수: %d번\n", sudden_acceleration);
    printf("급제동 수: %d번\n", sudden_braking);
  
}