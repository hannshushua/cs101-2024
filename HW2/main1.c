#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct randnum{
    int lottonum[7];
};
typedef struct randnum randNum;

int main (){
    int i = 0, j, k, n = 1, x, newnum = 0, repeat = 0;
    FILE *fp = fopen("lotto.txt", "w+");
    int test[7] = {0};

    printf("======== lotto%d ========\n", 649);
    fprintf(fp, "======== lotto%d ========\n", 649);

    TIME();

    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩: ");
    fprintf(fp, "歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩: ");

    scanf("%d", &x);
    randNum lotto[x];

    printf("已為您購買的 %d 組樂透彩組合輸出至lotto.txt\n", x);
    fprintf(fp, "已為您購買的 %d 組樂透彩組合輸出至lotto.txt\n", x);

    srand(time(NULL));
    for(int a = 0 ; a < x ; a++){
        
        while(n <= 7){
            newnum = rand()%69 + 1;
            repeat = 0;

            for(i = 0 ; i < n ; i++){
                if(test[i] == newnum){
                    repeat = 1;
                    break;
                }
            }
            if(!repeat){
                test[n - 1] = newnum;
                n++;
            }
        }
        n = 1;
        for(int b = 0 ; b < 7 ; b++){
            lotto[a].lottonum[b+1] = test[b];
            test[b] = 0;
        }
    }
    for(int i = 0 ; i < 5 ; i++){
        printf("[%d]: ", i + 1);
        fprintf(fp, "[%d]: ", i + 1);
        if(i + 1 > x){
            for(int j = 1 ; j <= 7 ; j++){
                printf("-- ");
                fprintf(fp, "-- ");
            }
        }else{
            for(int j = 1 ; j <= 7 ; j++){
                if(lotto[i].lottonum[j] < 10){
                    printf("0%d ", lotto[i].lottonum[j]);
                    fprintf(fp, "0%d ", lotto[i].lottonum[j]);
                }
                
                else{
                    printf("%d ", lotto[i].lottonum[j]);
                    fprintf(fp, "%d ", lotto[i].lottonum[j]);
                }
            }
        }
        printf("\n");
        fprintf(fp, "\n");
    }
    printf("======== csie@CGU ========");
    fprintf(fp, "======== csie@CGU ========");
}                                                           
void TIME(){    
    time_t cur_time;
    time(&cur_time);
    char *time_str = ctime(&cur_time);
    time_str[strlen(time_str) - 1] = '\0';
    printf("= %s =\n",time_str);
}
