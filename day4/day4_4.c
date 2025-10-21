#include <stdio.h>


void fruit(int count);

static int result = 0;

int main(void){
 
    fruit(1);
    return 0;
}

void fruit(int count){
    
    result += count;

    if (count == 10) {
        
        printf("%d\n",result);
        return;
    }
    
    fruit(count+1);
  
}

// void fruit(int count){
//     int result;

//     if (count == 1) return;
        
//     result = count + fruit(count-1);
//     return result;
  
// }