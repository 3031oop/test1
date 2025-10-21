#include <stdio.h>
#include <math.h>

int main(void) {
    double x,y,z;

    printf("실수 x 입력: ");
    scanf("%lf", &x);
    printf("실수 y 입력: ");
    scanf("%lf", &y);

    printf("sqrt(x) = %.4f\n", sqrt(x));
    return 0;
}