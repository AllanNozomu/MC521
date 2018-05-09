#include<stdio.h>

int main(){
    int q, m, n, i, j, r, qm;
    char c;
    int matrix[20][20];

    scanf("%d", &q);
    while(q--){
        scanf("%d %d ", &n, &m);
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                matrix[i][j] = 0;
        for ( i = 0; i < n; ++i){
            for ( j = 0 ; j < m; ++j){
                scanf("%c", &c);
                if (c == 'F'){
                    if(i > 0){
                        if(j > 0)
                            matrix[i-1][j-1]--;
                        matrix[i-1][j]--;
                        if(j < m - 1)
                            matrix[i-1][j+1]--;
                    }

                    if(j > 0)
                        matrix[i][j-1]--;
                    matrix[i][j] = 10000;
                    if(j < m - 1)
                        matrix[i][j+1]--;

                    if(i < n - 1){
                        if(j > 0)
                            matrix[i+1][j-1]--;
                        matrix[i+1][j]--;
                        if(j < m - 1)
                            matrix[i+1][j+1]--;
                    }
                } else {
                    matrix[i][j] += c - '0';
                }
            }
            scanf(" ");
        }
        qm = 0;
        r = 1;
        for ( i = 0; i < n && r; ++i){
            for ( j = 0 ; j < m && r; ++j){
                if (matrix[i][j] < 100 && matrix[i][j] != 0)
                    r = 0;
                if (matrix[i][j] > 100)
                    qm++;
            }
        }
        if (r && qm < m * n){
            printf("Well done Clark!\n");
        } else {
            printf("Please sweep the mine again!\n");
        }
    }
    return 0;
}