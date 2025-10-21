#include <stdio.h>

int main(void)
{
    /*< 사전 선정 정보 > -> md 로봇 (MDH 150)
    평균 전류(Rated current) : 8A
    평균 속도(Rated linear velocity) : 6.4km/h
    예비율 (임의로 선택) : 0.1 = 10%

    < 배터리 정보 >
    공정전압: 8V
    용량: 80A
    시스템 효율: 0.95 = 95%*/
    
    double I_load, vel, R, V, C, eta;
    int n;

    // 배터리 사양 및 환경정보 입력
    printf("----------사전 선정 정보----------\n");
    printf("평균전류 I_load [A] (부하측): "); if (scanf("%lf", &I_load)!=1) return 1;
    printf("평균속도 vel [km/h] : ");       if (scanf("%lf", &vel)!=1) return 1;
    printf("예비율 R [20%% = 0.2] : ");     if (scanf("%lf", &R)!=1) return 1;
    printf("모터의 개수 : ");                if (scanf("%d", &n)!=1) return 1;

    
    printf("---------배터리 정보---------\n");
    printf("공칭전압 V [V] : ");                 if (scanf("%lf", &V)!=1) return 1;
    printf("용량 C [Ah] : ");                   if (scanf("%lf", &C)!=1) return 1;
    printf("시스템 효율 eta [90%% = 0.9] : ");    if (scanf("%lf", &eta)!=1) return 1;

    if (V<=0 || C<=0 || I_load<=0 || vel<0 || R<0 || eta <=0 || eta>100 || n<0) {
        printf("입력값 범위를 확인하세요\n");
        return 1;
    } 

    //소비전력(W)
    const double  P = (V * I_load) / eta * n;

    //사용 가능 에너지(Wh)
    const double E_usable = V * C * eta * (1 - R);
    
    //런타임 계산(h)
    const double t_h = E_usable / P;
    const double t_min = t_h * 60.0;

    //주행거리 계산(km)
    const double d_km = vel * t_h;

    //출력결과
    printf("[결과]\n");
    printf("사용 가능 에너지 E_usable : %.2lf Wh \n", E_usable);
    printf("런타임 t                 : %.2lf h (%.1lf min) \n", t_h, t_min);
    printf("주행거리 d               : %.2lf km \n",d_km);
    printf("(계산 가정 : 전압강하/온도영향 무시, 평균전류 일정, 전류는 부하측 기준)\n");

    return 0;
}