#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void merge(int *arr, int beg, int mid, int end);
void merge_sort(int* arr, int beg, int end);
void print_arr(int arr[], int size);

long long int inv = 0;

int main(int argc, char **argv){
    
    int n;
    scanf("%d", &n);
    int arr[n];

    
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }

    merge_sort(arr, 0, n-1); 

    
    printf("%lld\n", inv);
}

void merge_sort(int arr[], int beg, int end){

    if(beg < end){
        int mid = floor((beg+end)/2);

        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
    
    return;
}

void merge(int arr[], int beg, int mid, int end){

    int n1 = mid - beg + 1; //number of elements in left array.
    int n2 = end - mid; //number of elements in right array.
    
    int l[n1+1]; //we add one more element for the sentinel element
    int r[n2+1];

    for(int i = 0; i < n1; i++)
        l[i] = arr[beg + i]; //the first half of the array is put into the left subarray
    
    for(int j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j]; //the second half is punt into the right subarray
    
    l[n1] = RAND_MAX; //sentinel element, in order to use for loops
    r[n2] = RAND_MAX;
    
    int i = 0;
    int j = 0;
    int k = beg;

    for(k = beg; k <= end; k++){
    
        //comparison between the left and right subarrays
        if(l[i] < r[j]){
            arr[k] = l[i];
            i++;
	}
        else{
            arr[k] = r[j];
            if(i < n1)
	        inv+= n1 - i;
	    j++;
	    
        }
    }
}

void print_arr(int arr[], int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}
