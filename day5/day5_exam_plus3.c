// 3) 상승할때 상승, 하강할때 하강하는 개수가 10개이상(방향성 유지 10개 이상)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int N,i,count;
    double speed[10000];
    double delta;
    double random;
    
    printf("주행 로그 개수 N: ");
    scanf("%d",&N);

    
    srand(time(NULL)); // 랜덤 초기화
    speed[0] = rand() %100;
    do {
        delta = (rand() % 19) - 9; // -9 ~ +9
    } while (delta == 0);
    printf("변화량: %.lf\n",delta);
    speed[1] = speed[0]+delta;


    count = 0;
    for (i=1; i<N; i++){
        if (count == 9){
            do {
                delta = (rand() % 19) - 9; // -9 ~ +9
            } while (delta == 0);    
            speed[i] = speed[i-1] + delta;
            if (speed[i] < 0) speed[i] = 0;
            if (speed[i] > 99) speed[i] = 99;
            count = 0;
        }   

        else {
            // 상승일 때
            if (speed[i]>speed[i-1]) {
                if (speed[i] == 99) {
                    delta = -(rand() % 9 + 1);
                    speed[i+1] = speed[i] + delta;
                    count = 0;
                }
                else {
                    delta = (rand() % 9)+1 ;
                    speed[i] = speed[i-1] + delta;
                    if (speed[i] < 0) speed[i] = 0;
                    if (speed[i] > 99) speed[i] = 99;
                    count++;

                }
        
            }
            // 하강일 때
            if (speed[i]<speed[i-1]) {
                if (speed[i] == 0) {
                    delta = (rand() % 9)+1 ;
                    speed[i] = speed[i-1] + delta;
                    count = 0;
                }
                else {
                    delta = -(rand() % 9 + 1) ;
                    speed[i] = speed[i-1] + delta;
                    if (speed[i] < 0) speed[i] = 0;
                    if (speed[i] > 99) speed[i] = 99;
                    count++;

                }
                
            }
                
        }      
        
        printf("속도 값: %.lf  ",speed[i]);
        printf("변화량: %.lf  ",delta);
        printf("반복 횟수: %d\n", count);
    }

}