#include <bits/stdc++.h>
using namespace std;

#define N (int) 10e5
#define K 10

int memo[N][K];
int matrix[N][K];

void cost(int row, int column, int k, int n, int last_column)
{
        for(int i = 0; i < k; i++){
                memo[n-1][i] = matrix[n-1][i];
        }

        int m1 = 0;
        for(int i = n-1; i >= 0; i--){
                int m2 = 0;
                int m1_pos = 0;

                for(int j = 0; j < k; j++){
                        if(memo[i][j] > m1){
                                m1_pos = j;
                                m2 = m1;
                                m1 = memo[i][j];
                        }
                        else if(memo[i][j] > m2){
                                m2 = memo[i][j];
                        }
                }
                for(int l = 0; l < k; l++){
                        memo[i-1][l] = m1 + matrix[i-1][l];
                }
                memo[i-1][m1_pos] = m2 + matrix[i-1][m1_pos];
        }
        printf("%d\n", m1);
}

int main (void)
{

        int n, k;
        scanf(" %d %d", &n, &k);

        for(int i = 0; i < n; i++){
                for(int j = 0; j < k; j++){

                        scanf(" %d", &matrix[i][j]);
                        memo[i][j] = 0;
                }
        }

        
        cost(0, 0, k, n, 0);

        return 0;
}