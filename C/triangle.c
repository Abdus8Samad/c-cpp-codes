#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double area(triangle t){
    double p = 1.0 * (t.a + t.b + t.c) / 2;
    double ret = p * (p - t.a) * (p - t.b) * (p - t.c);
    return ret;
}
void sort_by_area(triangle* arr, int n) {
    int i = 0;
    for(;i < n - 1;i++){
        int j = 0;
        for(;j < n - i - 1;j++){
            if(area(arr[j]) > area(arr[j + 1])){
                triangle temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n, i = 0,k,k2;
    scanf("%d", &n);
    k2 = k = n;
    triangle* arr = (triangle*)calloc(n, sizeof(triangle));
    // triangle* arr2 = (triangle*)calloc(n, sizeof(triangle));
    while(n-- && ++i) scanf("%d %d %d", &arr[i - 1].a, &arr[i - 1].b, &arr[i - 1].c);
    // i = 0;
    // while(k2-- && ++i) scanf("%d %d %d", &arr2[i - 1].a, &arr2[i - 1].b, &arr2[i - 1].c);
    sort_by_area(arr, k);
    i = 0;
    while(k-- && ++i){
        printf("%d %d %d %f\n", arr[i - 1].a, arr[i - 1].b, arr[i - 1].c, area(arr[i - 1]));
        // printf("%d %d %d %d\n", arr2[i - 1].a, arr2[i - 1].b, arr2[i - 1].c, area(arr2[i - 1]));
    }
}