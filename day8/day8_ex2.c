// 가로 세로의 합 구하기(포인터 사용)
#include <stdio.h>

int main(void){

    int ary1[6] = {1,2,3,4,5,0};
    int ary2[6] = {6,7,8,9,10,0};
    int ary3[6] = {11,12,13,14,15,0};
    int ary4[6] = {16,17,18,19,20,0};
    int ary5[6] = {0,0,0,0,0,0};
    int *num[5] = {ary1, ary2, ary3 ,ary4, ary5};

    int i, j;
    

    for (j=0; j<5; j++){
        for (i=0; i<4; i++){ 
            num[4][j] += num[i][j];
        }
        
    }

    for (i = 0; i<5; i++){
        for (j=0; j<6; j++){
            if (j<5) {
                num[i][5] += num[i][j];
            }
            printf("%5d", num[i][j]);
            
        }
        printf("\n");
    }



    return 0;
}