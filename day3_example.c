#include <stdio.h>

int main(void){

    double m,R,t,G,SF,margin;
    int N;
    const double c = 0.018;
    const double g = 9.81;

    int i;

    printf("총 하중(kg): ");                 if (scanf("%lf",&m)!=1) return 1;
    printf("구동 바퀴 수: ");                 if (scanf("%d",&N)!=1) return 1;
    printf("안전계수: ");                     if (scanf("%lf",&SF)!=1) return 1;
    printf("설계마진(20%% == 1.2로 입력): ");  if (scanf("%lf",&margin)!=1) return 1;

    
    for (i=0; i<5; i++){
        printf("\n모터 정격 토크: ");                if (scanf("%lf",&t)!=1) return 1;
        printf("감속비: ");                       if (scanf("%lf",&G)!=1) return 1;
        printf("바퀴 반지름(m): ");                if (scanf("%lf",&R)!=1) return 1;

        double W = m * g;
        double F_min = c * W * SF * margin;
        double F_motor = (t * G / R) * N;


        printf("\n필요한 최소 견인력 : %.2f [N]\n", F_min);
        printf("모터가 낼 수 있는 견인력 : %.2f [N]\n", F_motor);

        if (F_min >=F_motor){
        printf("판정 : 불만족 (더 큰 모터나 감속비가 필요.)\n");
        }
        else{
            printf("판정 : 만족 (모터 견인력이 충분합니다.)\n");
        }

        
    } 
    
    
    return 0;

}