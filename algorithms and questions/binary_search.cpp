#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int t;
    cin>>t;
    cout<<binary_search(nums, t)<<endl;
    return 0;
}
