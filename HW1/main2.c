#include <stdio.h>
//type arrayname[arraysize]; 
//start from 0 ;

int main (){

    char a[] = "A4B1C3f3";
    int i;
    int j;
    for(i = 0 ; i < (int)sizeof(a) ; i+=2){
        for(j = 1 ; j <= a[i + 1] - '0' ; j++){
            printf("%c", a[i]);
        }
    }
    return 0;
}
