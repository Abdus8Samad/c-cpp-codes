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
    double p = (t.a + t.b + t.c) / 2;
    double ret = p * (p - t.a) * (p - t.b) * (p - t.c);
    return pow(ret, 0.5);
}
void sort_by_area(triangle* arr, int n) {
    int i = 0;
    for(;i < n;i++){
        int j = 0;
        for(;j < n - i;j++){
            if(area(arr[j]) > area(arr[j + 1])){
                triangle temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("\nFROM HERE\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}