#include <stdio.h>

void swap(double *pa, double *pd);
void line_up(double *maxp, double *midp, double *minp);

int main(void){
    double max, mid, min;

    printf("실수값 3개 입력 :");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("정렬된 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

    return 0;
}

void swap(double *pa, double *pb){
    double temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double *maxp, double *midp, double *minp){
    // // max의 값이 가장 작은 값일 때
    // if (*maxp < *midp && *maxp < *minp ) {
    //     swap(maxp,minp);
    //     if (*midp > *maxp) swap(maxp, midp);       
    // } 
    // // mid의 값이 가장 작은 값일 때   
    // else if (*midp < *maxp && *midp < *minp) {
    //     swap(midp, minp);
    //     if (*midp > *maxp) swap(maxp, midp);
    // }
    // // min의 값이 가장 작은 값일 때
    // else {
    //     if (*maxp < *midp) swap(maxp, midp);
    // }

    if (*midp > *maxp) swap(maxp, midp);
    if (*minp > *maxp) swap(maxp, minp);
    if (*minp > *midp) swap(midp, minp);
         
}
