// Using Binary Search
#include <bits/stdc++.h> 
int CountSmallerThanOREqualToMid(vector<int> &arr,int target){
    int low=0;
    int high=arr.size()-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<=target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    int low=0;
    int high=INT_MAX;
    int mid;

    while(low<=high){
        mid=(low+high)/2;
        int cnt=0;
        int m=arr1.size();
        int n=arr2.size();
        cnt=CountSmallerThanOREqualToMid(arr1,mid);
        cnt+=CountSmallerThanOREqualToMid(arr2,mid);
        if(cnt<=k-1){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

// Using Recursion -> Convert While loops into returning to same function
#include <bits/stdc++.h>

int CountSmallerThanOREqualToMid(vector<int> &arr, int target, int low, int high) {
    if (low > high) {
        return low;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
        return CountSmallerThanOREqualToMid(arr, target, mid + 1, high);
    } else {
        return CountSmallerThanOREqualToMid(arr, target, low, mid - 1);
    }
}

int findKthElement(vector<int> &arr1, vector<int> &arr2, int k, int low, int high) {
    if (low > high) {
        return low;
    }

    int mid = low + (high - low) / 2;
    int cnt = CountSmallerThanOREqualToMid(arr1, mid, 0, arr1.size() - 1);
    cnt += CountSmallerThanOREqualToMid(arr2, mid, 0, arr2.size() - 1);

    if (cnt <= k - 1) {
        return findKthElement(arr1, arr2, k, mid + 1, high);
    } else {
        return findKthElement(arr1, arr2, k, low, mid - 1);
    }
}
