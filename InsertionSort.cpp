#include <bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define SZ 100

void InsertionSort(int arr[], int elements)
{
    int j,tmp;

    for(int i = 0 ; i < elements; i++){
        j = i;

        while(j > 0 && (arr[j - 1] > arr[j]) ){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }

    for(int i = 0 ; i < elements ; i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int elements,arr[SZ],i;

    sc(elements);

    for(i = 0 ; i < elements; i++){
        sc(arr[i]);
    }

    InsertionSort(arr,elements);
}
