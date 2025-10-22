// 가장 가까운 거리
#include <stdio.h>

int main(void){
    int N,i,j;
    int index;
    double min;
    double d[360];

    printf("라이다 스캔 데이터 개수(개):");
    if(scanf("%d",&N) !=1) return 1;


    for (i=0; i<N; i++){
        printf("%3d도 거리값(cm)(0~500): ", i);
        scanf("%lf",&d[i]);
    }

    min = d[0];
    for (i=0; i<N; i++){
        if (d[i] < min){
            min = d[i];
            index = i;
        }
    }
     printf("\n[라이다 최소 거리 탐색 결과]\n");
    printf("가장 가까운 거리: %.1f cm\n", min);
    printf("장애물 방향: %d°\n", index);
    return 0;
}