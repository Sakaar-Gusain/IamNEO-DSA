/*
vector<int> nums = {3, 34, 4, 12, 5, 2};
int target = 9;
// Expected Output: Subset with the given sum exists.

Test Case:
vector<int> nums = {1, 2, 3, 8, 7, 4};
int target = 15;
// Expected Output: Subset with the given sum exists.

Test Case:
vector<int> nums = {1, 2, 3, 8, 7, 4};
int target = 30;
// Expected Output: Subset with the given sum does not exist.
*/
#include<bits/stdc++.h>
using namespace std;
 
bool subsetSumHelper(vector<int>& nums, int target, int currentsum, int index)
{
    if(currentsum == target)
    {
        return true;
    }
    if(index >= nums.size() || currentsum > target)
    {
        return false;
    }
    if(subsetSumHelper(nums, target, currentsum + nums[index], index + 1))
    {
        return true;
    }
    if(subsetSumHelper(nums, target, currentsum, index + 1))
    {
        return true;
    }
    return false;
    
}
bool subsetSum(vector<int>& nums, int target)
{
    return subsetSumHelper(nums, target, 0 , 0);
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 20;
    if(subsetSum(nums, target))
    {
        cout<<"Subset with the given sum exists."<<endl;
    }
    else
    {
        cout<<"Subset with the given sum does not exixt."<<endl;
    }
}