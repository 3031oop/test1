// 가장 가까운 거리 3개 출력
#include <stdio.h>
#include <float.h>

int main(void){
    int N,i,j;
    int index[360];
    double min[360];
    double d[360];
    
    int min_index1 = -1, min_index2 = -1, min_index3 = -1;
    double min_value1, min_value2, min_value3;

    printf("라이다 스캔 데이터 개수(개):");
    if(scanf("%d",&N) !=1) return 1;

    // 입력 받은 데이터 개수만큼 반복
    for (i=0; i<N; i++){
        printf("%3d도 거리값(cm)(0~500): ", i);
        scanf("%lf",&d[i]);
    }

    min_value1 = DBL_MAX;
    min_value2 = DBL_MAX;
    min_value3 = DBL_MAX;
    
    for (i = 0; i < N; i++) {
        
        // 1. 현재 값이 1순위 최소값보다 작은 경우
        if (d[i] < min_value1) {
            // 기존 2순위를 3순위로 밀어냄
            min_value3 = min_value2;
            min_index3 = min_index2;
            
            // 기존 1순위를 2순위로 밀어냄
            min_value2 = min_value1;
            min_index2 = min_index1;
            
            // 새로운 값을 1순위로 지정
            min_value1 = d[i];
            min_index1 = i;
        } 
        // 2. 1순위보다는 크지만 2순위 최소값보다 작은 경우
        else if (d[i] < min_value2) {
            // 기존 2순위를 3순위로 밀어냄
            min_value3 = min_value2;
            min_index3 = min_index2;
            
            // 새로운 값을 2순위로 지정
            min_value2 = d[i];
            min_index2 = i;
        } 
        // 3. 1, 2순위보다는 크지만 3순위 최소값보다 작은 경우
        else if (d[i] < min_value3) {
            // 새로운 값을 3순위로 지정
            min_value3 = d[i];
            min_index3 = i;
        }

        
    }
    
    printf("\n[라이다 최소 거리 탐색 결과]\n");
	printf("가장 가까운 거리: %.1f cm\n", min_value1);
    printf("장애물 방향(각도): %d°\n", min_index1);
    printf("두 번째 가까운 거리: %.1f cm\n", min_value2);
    printf("장애물 방향(각도): %d°\n", min_index2);
    printf("세 번째 가까운 거리: %.1f cm\n", min_value3);
    printf("장애물 방향(각도): %d°\n", min_index3);

	return 0;

}