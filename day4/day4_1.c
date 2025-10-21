#include <stdio.h>
#include <math.h>

double clip(double value, double min, double max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

int main(void){
    double m, Tm, G, eta, r, c, SF;
    int Nm;
    const double g = 9.81;



    printf("총 질량 m(kg): ");
    if (scanf("%lf",&m) != 1) return 1;
    printf("모터 정격토크 Tm(N*m): ");
    if (scanf("%lf",&Tm) != 1) return 1;
    printf("구동 모터 수(개): ");
    if (scanf("%lf",&Nm) != 1) return 1;
    printf("감속비 G: ");
    if (scanf("%lf",&G) != 1) return 1;
    printf("구동 효율 eta(0~1): ");
    if (scanf("%lf",&eta) != 1) return 1;
    printf("바퀴 반지름 r(m): ");
    if (scanf("%lf",&r) != 1) return 1;
    printf("구름 계수 c(예:0.1~0.2): ");
    if (scanf("%lf",&c) != 1) return 1;
    printf("안전계수 SF(>=1): ");
    if (scanf("%lf",&SF) != 1) return 1;

    if (m<=0 || Tm<=0 || Nm<=0 || G<=0 || eta<=0 ||eta>1 || r<=0 || c<=0 || SF<1){
        printf("입력값 범위를 확인하세요.\n");
        return 1;
    }

    //계산
    double Ttot = Nm * Tm * G * eta;
    double Favail = Ttot / r;
    double mg = m * g;

    // 등판 최대각 (안전계수 적용)
    double sin_theta = (Favail/(SF-c*mg)/mg);
    if (sin_theta < 0.0) sin_theta = 0.0;
    if (sin_theta > 1.0) sin_theta = 1.0;
    
    double theta_rad = asin(sin_theta);
    double theta_deg = theta_rad *180.0 /M_PI;
    double grade = tan(theta_rad) * 100;

    printf("총 가용 견인력: %.2lf N\n", Favail);
    printf("등판 가능 최대각: %.2lf\n", deg_max);
    printf("등판율: %.2lf %%\n", grade);
}