#include <stdio.h>

int main(void)
{
    /*< 사전 선정 정보 > -> md 로봇 150
    평균 전류(Rated current) : 8A
    평균 속도(Rated linear velocity) : 6.4km/h
    예비율 (임의로 선택) : 0.1 = 10%

    < 배터리 정보 >
    공정전압: 8V
    용량: 80A
    시스템 효율: 0.95 = 95%*/
    
    
    int I_load = 8 , V= 24, C = 60;
    double E_usable, t, d, P, vel = 6.4, R=0.1, eta=0.95;

    E_usable = V * C * eta * (1 - R);
    P = (V * I_load) / eta;
    t = E_usable / P;
    d = vel * t;


    printf("----------사전 선정 정보----------\n");
    printf("평균전류 I_load [A] (부하측): %d \n", I_load);
    printf("평균속도 vel [km/h] : %.1lf \n", vel);
    printf("예비율 R [20%% = 0.2] : %.1f \n", R);

    printf("---------배터리 정보---------\n");
    printf("공칭전압 V [V]: %d \n", V);
    printf("용량 C [Ah]: %d \n", C);
    printf("시스템 효율 eta [90%% = 0.9]: %.2lf \n", eta);

    printf("[결과]\n");
    printf("사용 가능 에너지 E_usable : %.2lf Wh \n", E_usable);
    printf("런타임 t                : %.2lf h (%.2lf min) \n", t, t*60);
    printf("주행거리 d               : %.2lf km \n",d);
    printf("(계산 가정 : 전압강하/온도영향 무시, 평균전류 일정, 전류는 부하측 기준)\n");
}