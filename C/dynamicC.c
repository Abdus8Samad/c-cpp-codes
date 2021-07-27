#include <stdio.h>
#include <stdlib.h>

int main() {
    int* total_number_of_books;
    int** total_number_of_pages;
    int total_number_of_shelves = 5;
    total_number_of_books = (int*)calloc(total_number_of_shelves, 4);
    total_number_of_pages = (int**)calloc(total_number_of_shelves, 8);
    int i = 0;
    for(;i<total_number_of_shelves;i++){
        total_number_of_pages[i] = (int*)calloc(10, 4);
    }
    int total_number_of_queries = 5;
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_pages[x][total_number_of_books[x]] = y;
            total_number_of_books[x]++;
        } 
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++) printf("%d ", total_number_of_pages[i][j]);
        printf("\n");
    }
    return 0;
}