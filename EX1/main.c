#include <stdio.h>

void print_sp(int rows, int n){
    for(int sp = 0 ; sp < rows - n ; sp++){
        printf(" ");
    }
}

void print_num(int n){
    int i = n ;
    for(i = 1 ; i <= n ; i++){
        printf("%d ", n);
    }
}
int main (){

    int rows = 9;
    for(int i = 1 ; i <= rows ; i++){
        print_sp(rows,i);
        print_num(i);
        printf("\n");
    }
    return 0 ;

}
