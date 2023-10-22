#include <bits/stdc++.h>
using namespace std;

void perm(int* arr, int size, int count)
{
        if(count == size){
                for(int i = 0; i < size; i++){
                        printf("%d ", arr[i]);
                }
                printf("\n");
                
                return;
        }

        for(int i = count; i < size; i++){
                swap(arr[i], arr[count]);
                perm(arr, size, count+1);
                swap(arr[i], arr[count]);        
        }

}

void subsets(int* arr, int size)
{
        int s = 1 << size;
        for(int i = 0; i < s; i++){
                for(int j = 0; j < size; j++){
                    int mask = 1 << j;
                    if(i&mask) printf("%d ", arr[j]);          
                }

                printf("\n");
        }        
}

int main(void)
{
        int n;
        scanf(" %d", &n);
        int arr[n];
        for(int i = 0; i < n; i++){
                scanf(" %d", &arr[i]);
        }

        // perm(arr, n, 0);
        subsets(arr, n);
        
        return 0;
}
