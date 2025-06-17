// Problem : https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// ------------------  Solution -----------------------------
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;
    int right = mid + 1;

    int cnt = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }


    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
    
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size()-1);
        
    }
};

/*

--------------------- Time Complexity and Space Complexity -----------------------
|                                                                                |
|                      T.C :  O(N*logN)         S.C : O(N)                       |
|                                                                                |
----------------------------------------------------------------------------------

*/