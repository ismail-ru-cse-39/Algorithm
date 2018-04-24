#include <bits/stdc++.h>

using namespace std;

#define SZ 10000
#define sc(a) scanf("%d",&a)

int arr[SZ];
int Big_int = 99999;

int MergeSort(int arr[], int low, int high);
int Merge(int arr[],int low, int mid, int high);

int main()
{
    int n,i;
    sc(n);

    for(i = 0 ; i < n ; i++){
        sc(arr[i]);
    }

    MergeSort(arr,0,n-1);

    for(i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }

}

int MergeSort(int arr[], int low, int high)
{
    int mid;
    if(low < high){
        mid = (low + high)/2;
        //divide and conquer
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);

        //combine
        Merge(arr,low,mid,high);
    }

    return 0;
}

int Merge(int arr[],int low, int mid, int high)
{
    int arr1[SZ/2],arr2[SZ/2];//temporary array

    int n1,n2,i,j,k;

    n1 = mid - low + 1;
    n2 = high-mid;

    for(i = 0 ; i < n1 ; i++){
        arr1[i] = arr[low+i];
    }
    for(j = 0 ; j < n2 ; j++){
        arr2[j] = arr[mid+j+1];
    }

    arr1[i] = Big_int;  //to mark the end of the array
    arr2[j] = Big_int;

    i = 0;
    j = 0;

    for(k = low ; k <= high ; k++){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i++];
        }
        else{
            arr[k] = arr2[j++];
        }
    }

    return 0;
}
