#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *inpfp;
    char buffer[1000];
    int line = 0;
    inpfp = fopen("C:/Users/hiimd/Desktop/vscode/CGUCSIE/output/main3.c", "r");
    if(inpfp == NULL){
        printf("無法開啟檔案");
        return -1;
    }

    while(fgets(buffer, sizeof(buffer), inpfp)){
        line++;
        if(strstr(buffer, "int main(){") != NULL){
            printf("%d %s", line, buffer);
            break;
        }
    }
    fclose(inpfp);
}
