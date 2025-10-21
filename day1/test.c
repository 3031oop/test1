#include <stdio.h>

int main(void){
    
    printf("Be happy\n");
    printf("12345678910\n");
    printf("My\tfriend\n");
    printf("Goot\bd\tchance\n");
    // t를 d로 바꾸고 탭 위치로 이동(\t) 후에 "chance"를 출력하고 줄을 바꿈(\n)
    printf("Cow\rW\a\n");
    //맨 앞으로 이동(\r)해 C를 W로 바꾸고 벨소리(\a)를 내고 줄을 바꿈(\n)
    
    printf("%d\n", 10);
    printf("%lf\n", 3.4);
    printf("%.1lf\n", 3.45);
    printf("%.10lf\n", 3.4);

    printf("%d와 %d의 합은 %d 입니다.\n",10,20,10+20);
    printf("%.1lf-%.1lf=%.1lf\n",1.4,1.5,1.4+1.5);



    return 0;

}
