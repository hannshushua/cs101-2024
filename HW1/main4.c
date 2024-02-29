#include <stdio.h>
//type arrayname[arraysize]; 
//start from 0 ;

int main (){

    char a[] = "Hello";
    int i;

    for(i = (int)sizeof(a) - 1 ; i >= 0 ; i--){
        printf("%c", a[i]);
    }
    
    return 0;
}
