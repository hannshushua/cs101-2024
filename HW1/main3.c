#include <stdio.h>
#include <string.h>

int main (){

    char a[100]; // 0123 4567 
    scanf("%s", &a);
    int length = strlen(a);
    int x = 1, sum = 0, b1 = 0, b2 = 0;
    for(int i = length - 1 ; i >= 0 ; i--){
        if(i > 3){//b2
            if(a[i] - '0')sum+=x;
            x *= 2;
            if(i == 4){
                b2 = sum;
                sum = 0;
                x = 1;
            }
        }
        else{//b1
            if(a[i] - '0')sum+=x;
            x *= 2;
            if(i == 0){
                b1 = sum;
                sum = 0;
            }
        }
    }
    if(b1 == 0 && b2 == 0)printf("0\n");
    else if (b1 == 0 && b2 != 0)printf("%X\n",b2);
    else printf("%X%X\n", b1, b2);
    return 0;
}
