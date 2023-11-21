#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define MAX 1000010

void erastostenes(bitset<MAX>& b)
{
    b[0] = 0;
    b[1] = 0;
    for(long long int i = 2; i < MAX; i++){
        if(b[i]){
            for(int j = 2*i; j < MAX; j+=i){
                b[j] = 0;
            }
        }
    }
}


int main (void)
{
    bitset<MAX> b;
    b.set();
    erastostenes(b);
    long long int n = 0;

    scanf(" %lld", &n);
    long long int k2 = 0;
    long long int k = 0;
    for(long long int i = 0; i < n; i++){
        scanf(" %lld", &k2);
        k = sqrt(k2);
        if(k*k == k2 && b[k])
            printf("1");
        else printf("0");
    }

    return 0;
}

