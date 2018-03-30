#include <bits/stdc++.h>
using namespace std;
int ROW,COL;

int peakFinder(int arr[100][100], int n, int m, int mid);
int findLargest(int arr[100][100], int n, int mid, int &max_value);

int main()
{
    int n,m,i,j,arr[100][100];

    cout<<"Enter the number of row and column : ";
    cin>>n>>m;
    ROW = n;
    COL = m;

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int result = peakFinder(arr,n,m,m/2);

    cout<<result<<endl;

    return 0;
}

int peakFinder(int arr[100][100], int n, int m, int mid){
    int max_value = 0;
    int max_index = findLargest(arr,n,mid,max_value);

    if(mid == 0  || mid == m-1){
        return max_value;
    }
    if(max_value >= arr[max_index][mid-1] && max_value >= arr[max_index][mid+1]){
        return max_value;
    }

    if(max_value < arr[max_index][mid-1]){
        return peakFinder(arr, n, m, mid - mid/2);
    }
    if(max_value < arr[max_index][mid+1]){
        return peakFinder(arr, n, m, mid + mid/2);

    }

}

int findLargest(int arr[100][100], int n, int mid, int &max_value){
    int i;
    int mx_index = 0;

    for(i = 0 ; i < n; i++){
        if(max_value < arr[i][mid]){
            max_value = arr[i][mid];
            mx_index = i;
        }
    }

    return mx_index;

}
