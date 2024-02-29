#include <stdio.h>
//type arrayname[arraysize]; 
//start from 0 ;

int main (){

    char a[] = "AABBBCCCCddd";
    int i ;
    int j = 0;
    for(i = 0 ; i < (int)sizeof(a) ; i++){
        if(i == 0 || a[i] == a[i - 1]){
            j++;
        }else{
            printf("%c%d", a[i - 1], j);
            j = 1;
        }
    }
    return 0;
}
