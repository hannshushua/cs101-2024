#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buffer[1000];
    FILE *inpfp, *outpfp;

    inpfp = fopen("C:/Users/hiimd/Desktop/vscode/CGUCSIE/main2.c", "r");
    if(inpfp == NULL){
        printf("1 檔案開啟錯誤");
        return -1;
    }

    outpfp = fopen("main2.txt", "w+");
    if(outpfp  == NULL){
        printf("2 檔案開啟錯誤");
        fclose(inpfp);
        return -1;
    }

    while(fgets(buffer, sizeof(buffer), inpfp) != NULL){
        fputs(buffer , outpfp);
    }
    
    fclose(inpfp);
    fclose(outpfp);
    return 0 ;
}
