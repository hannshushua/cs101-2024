#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    FILE *fp;
    int a[] = {0,1,2};
    int a_read[3];
    char b[] = "ABC";
    char b_read[3];
    float c[] = {1.1 , 1.2 , 1.3};
    float c_read[3];

    fp = fopen("a.bin", "w+");
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(a_read, sizeof(int), 3, fp);
    fread(b_read, sizeof(char), 3, fp);
    fread(c_read, sizeof(float), 3, fp);
    fclose(fp);
    for(int i = 0 ; i < 3 ; i++){
        printf("%d ", a_read[i]);
    }
    printf("\n");
    for(int i = 0 ; i < 3 ; i++){
        printf("%c ", b_read[i]);
    }
    printf("\n");
    for(int i = 0 ; i < 3 ; i++){
        printf("%.1f ", c_read[i]);
    }
    return 0;
}
