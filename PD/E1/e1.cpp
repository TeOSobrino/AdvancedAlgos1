#include <bits/stdc++.h>
using namespace std;

#define MAX (int)1e5 + 10

long long int memo[MAX];

// void print_mem(long long int *memo, int n)
// {
//         for (int i = 0; i < n; i++)
//                 printf("%lld ", memo[i]);
//         printf("\n");
// }

// void find_best_price(vector<int> input, int curr, int max)
// {
//         if (memo[curr] != -1)
//                 return;

//         if (curr == max) {
//                 memo[curr] = 0;
//                 return;
//         }

//         find_best_price(input, curr + 2, max);

//         if (curr == max) {
//                 memo[curr] = 0;
//                 return;
//         }
//         if (curr + 1 == max) {
//                 memo[curr] =
//                     abs(input[curr] - input[curr + 1]) + memo[curr + 1];
        
//         } else if (curr + 2 == max) {
//                 memo[curr] =
//                     min(abs(input[curr] - input[curr + 1]) + memo[curr + 1],
//                         abs(input[curr] - input[curr + 2]) + memo[curr + 2]);
        
//         } else {
//                 memo[curr] =
//                     min(abs(input[curr] - input[curr + 1]) + memo[curr + 1],
//                         abs(input[curr] - input[curr + 2]) + memo[curr + 2]);
//                 memo[curr + 1] = min(
//                     abs(input[curr + 1] - input[curr + 2]) + memo[curr + 2],
//                     abs(input[curr + 1] - input[curr + 3]) + memo[curr + 3]);
//         }
// }

int main(void)
{

        int n;
        scanf(" %d", &n);
        vector<int> input;
        input.reserve(n);

        int k;
        for (int i = 0; i < n; i++) {
                scanf(" %d", &k);
                input.push_back(k);
        }

        for (int i = 0; i < n; i++) {
                memo[i] = -1;
        }

        memo[n-1] = 0;
        memo [n-2] = abs(input[n-2] - input[n-1]) + memo[n-1];
        int t = n-3;

        while(t >= 0){

                memo[t] = min( abs(input[t] - input[t + 1]) + memo[t + 1],
                        abs(input[t] - input[t + 2]) + memo[t + 2]);  
                t--;
        }

        printf("%lld\n", memo[0]);
        return 0;
}