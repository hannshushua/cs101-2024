#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//書籤
struct books{
    int BOOK_ID;
    int PRICE;
    char TITLE[100];
};
typedef struct books BOOKS;
void total_price(BOOKS book[], int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum+=book[i].PRICE;
    }
    printf("%d$\n", sum);
};

void list_book(BOOKS book[], int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d : %s\n", i + 1, book[i].TITLE);
    }
}

int main (){
    BOOKS book[6];
    
    book[0].BOOK_ID = 1;
    book[0].PRICE = 1000;
    strcpy(book[0].TITLE , "All the Light We Cannot See");

    book[1].BOOK_ID = 2;
    book[1].PRICE = 300;
    strcpy(book[1].TITLE , "The 38 Letters from J.D. Rockefeller to his son");
    
    book[2].BOOK_ID = 3;
    book[2].PRICE = 1000;
    strcpy(book[2].TITLE , "The Ballad of Songbirds and Snakes");

    book[3].BOOK_ID = 4;
    book[3].PRICE = 550;
    strcpy(book[3].TITLE , "Killers of the Flower Moon");

    book[4].BOOK_ID = 5;
    book[4].PRICE = 870;
    strcpy(book[4].TITLE , "Elon Musk");

    book[5].BOOK_ID = 6;
    book[5].PRICE = 1344;
    strcpy(book[5].TITLE , "Milk and Honey 12-Month 2024");

    
    printf("Total price = ");
    total_price(book, 6);
    printf("Book List :\n");
    list_book(book, 6);
    
    
    return 0;
}
