#include <stdio.h>

void multiplication(int i, int j){
    if(i < 1)return;
    printf("%d x %d = %d ", i, j, i*j);
    if(j == 1){
        printf("\n");
        i--;
        j = 9;
        multiplication(i,j);
    }else{
        multiplication(i,j-1);
        
    }
}
int main(){
    multiplication(9,9);
}
