#include <bits/stdc++.h>
using namespace std;

int peakFinder(int arr[],int low, int high, int n);

int main()
{
    int arr[1000],i,n;
    cin>>n;

    for(i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    int peak = peakFinder(arr,0,n-1,n);

    cout<<peak<<endl;

    return 0;
}

int peakFinder(int arr[],int low, int high, int n){
    int mid = low + (high - low)/2;

    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]) ){
        return arr[mid];
    }
    if(mid > 0 && arr[mid] < arr[mid - 1]){
        return peakFinder(arr,low,mid-1,n);
    }

    else{
        return peakFinder(arr,mid+1,n-1,n);
    }

}
