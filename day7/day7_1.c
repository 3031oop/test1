#include <stdio.h>

int main(void){
    // double a = 10.0;
    // double *p = &a;
    // int *pd;

    // pd = (int *)p;

    int a = 10;
    int *p = &a;
    double *pd;
    
    pd = (double *)p;
    printf("%d\n",*(int *)pd);

    return 0;
}

