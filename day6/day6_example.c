#include <stdio.h>

#define MAX_N 16

// ---- 함수 선언부 ----
void classify_by_threshold(const int value[], int label[], int n, int threshold);
int count_black(const int label[], int n);
double average_index_of_black(const int label[], int n, int black_count);

int main(void){
    int i, n;
    int label[20];
    int threshold;
    int value[20];
   

    // 센서 개수 입력
    printf("센서 개수 입력: ");
    if (scanf("%d", &n) != 1) return 0;
    if (n > MAX_N || n < 1){
        printf("1개 이상, 16개 이하로 입력해주세요 ");
        return 0;
    }

    // 센서값 입력 
    for (i=0; i<n; i++){
        printf("센서값 입력: ");
        scanf("%d",&value[i]);
    }

    // 임계값 입력
    printf("임계값 입력: ");
    scanf("%d", &threshold);



    classify_by_threshold(value, label, n, threshold); // 라인 판별 처리

    int black_count = count_black(label, n); // 검정 감지 개수


    // 라인 중심 위치 계산
    if (black_count == 0){
        printf("라인 없음");
    }

    else{
        double center = average_index_of_black(label, n, black_count);

        // 출력값
        printf("lable = ");
        for (i=0; i<n; i++){
            printf("%d ",label[i]);
        }
        printf("\nblack_count = %d\n", black_count);
        printf("index_avg = %.2f\n",center);

    }


    return 0;

}


// 임계값으로 분류
void classify_by_threshold(const int value[], int label[], int n, int threshold){
    for (int i=0; i<n; i++){
        if (value[i] < threshold) label[i] = 1;
        else label[i] = 0; 
        // 배열은 main문에서 같은 메모리를 사용하므로 반환하지 않아도 ㄱㅊ
    }
    
}

// 검정 가지 개수 계산
int count_black(const int label[], int n){
    int count = 0;
    
    for (int i=0; i<n; i++){
        count += label[i]; 
    }

    return count;

}


// 라인 중심 계산
double average_index_of_black(const int label[], int n, int black_count){
    int count;
    double sum_index = 0;
    double index_avg;
     
    for (int i=0; i<n; i++){
        sum_index += i * label[i];
    }

    index_avg = sum_index / black_count;

    return index_avg;

}