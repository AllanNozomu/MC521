#include<stdio.h>
#include<math.h>

int main()
{
    long int n, i, j, r;

    r = 0;
    scanf("%ld", &n);
    for (i = 2; i < sqrt(n) && !r; ++i){
        j = n / i;
        if (j != i && n % i == 0){
            printf("S\n");
            r = 1;
        }
    }
    if (!r){
        printf("N\n");
    }

    return 0;
}