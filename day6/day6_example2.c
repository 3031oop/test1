#include <stdio.h>

#define MAX_N 10

void adc_to_voltage(const int adc[],double v[], double Vref,int N);
void voltagae_to_distance(const double k,double v[],double d[], int N);

int main(void) {
    int i,N;
    int adc[MAX_N];
    double v[MAX_N];
    double d[MAX_N];
    double Vref;
    double k;

    // 입력값
    printf("ADC 값의 개수(N): ");
    scanf("%d",&N);

    for (i=0; i<N; i++){
        printf("%d번째 ADC값: ",i+1);
        scanf("%d",&adc[i]);
    }

    printf("기준 전압 값(Vref): ");
    scanf("%lf",&Vref);

    printf("거리 변환 상수 값(k): ");
    scanf("%lf",&k);
    
    // 함수 호출
    adc_to_voltage(adc,v,Vref,N);
    
    voltagae_to_distance(k,v,d,N);

    // 출력값
    printf("\n[결과]\n");
    printf("ADC      -> ");
    for (i=0; i<N; i++){
        printf("%d  ",adc[i]);
    }
    printf("\n전압(V)  -> ");
    for (i=0; i<N; i++){
        printf("%.2f  ",v[i]);
    }
    printf("\n거리(cm) -> ");
    for (i=0; i<N; i++){
        printf("%.2f  ",d[i]);
    }

}

void adc_to_voltage(const int adc[],double v[], double Vref, int N){
    for (int i=0; i<N; i++){
        v[i] = (adc[i] / 1023.0)* Vref;
        if (v[i] == 0){
            v[i] = 0.01;
        }
    }
}

void voltagae_to_distance(const double k,double v[],double d[], int N){
    for (int i=0; i<N; i++){
        d[i] = k / v[i];
    }
}
