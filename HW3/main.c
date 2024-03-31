#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct lottonum{
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
};
typedef struct lottonum lotto_record_t;

void savelotto(int n, int id){
    int newnum, repeat = 0, i, s = 0;
    lotto_record_t lot;
    lot.receipt_id = id;
    lot.receipt_price = 100 * n;
    
    char filename[100];
    sprintf(filename,"C:/Users/hiimd/Desktop/vscode/lotto/lotto[%05d].txt", lot.receipt_id);
    FILE *fp = fopen(filename,"w+");
    fprintf(fp, "======== lotto%03d ========\n", 649);
    fprintf(fp, "======== No.%05d ========\n", lot.receipt_id);
    
    srand(time(NULL));
    
    //計時間
    TIME(&lot);
    fprintf(fp,"=%s=\n", lot.receipt_time);
    
    // fprintf(fp,"=%s=\n",lot.receipt_time);
    for(int a = 0 ; a < n ; a++){//產生彩券號碼
        while(s <= 7){
            newnum = rand()%69 + 1;
            repeat = 0;
            for(i = 0 ; i < s ; i++){
                if(lot.lotto_set[a][i] == newnum){
                    repeat = 1;
                    break;
                }
            }
            if(!repeat){
                lot.lotto_set[a][s-1] = newnum;
                newnum = 0;
                s++;
            }
        }
        s = 1;
    }
    for(int i = 0 ; i < 5 ; i++){//印在每個彩券上
        
        fprintf(fp, "[%d]: ", i + 1);
        
        if(i + 1 > n){
            for(int j = 0 ; j < 7 ; j++){    
                fprintf(fp, "-- ");
            }
        }else{
            for(int j = 0 ; j < 7 ; j++){
                fprintf(fp, "%02d ", lot.lotto_set[i][j]);   
            }
        }
        fprintf(fp, "\n");
    }   
    fclose(fp);
    FILE *save = fopen("C:/Users/hiimd/Desktop/vscode/lotto/record.bin","ab+");
    fwrite(&lot,sizeof(lotto_record_t),1,save);//把每筆樂透資訊存入record.bin
    fclose(save);
}
int getid(){
    FILE *find = fopen("C:/Users/hiimd/Desktop/vscode/lotto/record.bin","rb+");
    fseek(find,0,SEEK_END);//定位到文件末端
    long size = ftell(find), count; // ftell = 當前位置 = 文件大小
    count = (size) / sizeof(lotto_record_t); //資料數 = lot的數量
    count;
    fclose(find);
    return count;
}
void openlot(int count){
    int i = 0 ,wincount = 0, N[3] = {0}, win = 0;
    lotto_record_t oplt;
    
    printf("請輸入中獎號碼 (最多三個) :");
    do{
        scanf("%d", &N[i]);
        i++;
        if(i > 3)break;
    }while(getchar() != '\n');

    printf("輸入中獎號碼為 : ");
    for(int i = 0 ; i < (sizeof(N) / sizeof(int)) ; i++){
        printf("%d ", N[i]);
    }
    printf("\n以下為中獎彩券:\n");
    int a = 1;
    FILE *openlot = fopen("C:/Users/hiimd/Desktop/vscode/lotto/record.bin","rb+");
    while(a <= count){
        fread(&oplt,sizeof(lotto_record_t),1,openlot);
        if(a == oplt.receipt_id){
            // printf("%d:\n", oplt.receipt_id);
            for(int b = 0 ; b < oplt.receipt_price / 100 ; b++){
                for(int c = 0 ; c < 7 ; c++){
                    if(oplt.lotto_set[b][c] == N[0] || oplt.lotto_set[b][c] == N[1] || oplt.lotto_set[b][c] == N[2])win = 1;
                    // printf("%02d ", oplt.lotto_set[b][c]);    
                }
                if(win){
                    if(!wincount){
                        printf("彩券 : No.%02d\n",oplt.receipt_id);
                        printf("售出時間 : %s\n", oplt.receipt_time);
                    }
                    printf("號碼 : ");
                    for(int c = 0 ; c < 7 ; c++){
                        printf("%02d ", oplt.lotto_set[b][c]);
                    }
                    printf("\n");
                    wincount = 1;
                }
                win = 0;
            }
        }
        // printf("\n");
        a++;
        wincount = 0;
    }
    fclose(openlot);
}
int main(){
    int n,id = 0;
    lotto_record_t data;
    scanf("%d", &n);
    FILE *record = fopen("C:/Users/hiimd/Desktop/vscode/lotto/record.bin","rb+");
    if(record == NULL){
        record = fopen("C:/Users/hiimd/Desktop/vscode/lotto/record.bin","wb+");
        id = 1;
        savelotto(n,id);
        fclose(record);
        return 1;
    }else{
        if(!n){
            openlot(getid());
        }
        else{
            fclose(record);
            savelotto(n,getid() + 1);
        }
        fclose(record);
    }
}
void TIME(lotto_record_t *lot){  
    time_t cur_time;
    time(&cur_time);
    char *time_str = ctime(&cur_time);
    time_str[strlen(time_str) - 1] = '\0';
    strcpy(lot->receipt_time, time_str);
}
