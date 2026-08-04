//leetcode problem 3731 find missing elements
//https://leetcode.com/problems/find-missing-elements/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissing(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = nums[i-1] + 1; j < nums[i]; j++){
                ans.push_back(j);
            }
        }
        return ans;
    }       
};

int main() {
    Solution solution;
    vector<int> nums = {4, 2, 1, 7};
    vector<int> missing = solution.findMissing(nums);

    cout << "Missing elements in nums: ";
    for(int num : missing){
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1,9};
    vector<int> missing2 = solution.findMissing(nums2);

    cout << "Missing elements in nums2: ";
    for(int num : missing2){
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> missing3 = solution.findMissing(nums3);

    cout << "Missing elements in nums3: ";
    for(int num : missing3){
        cout << num << " ";
    }
    cout << endl;



    return 0;
}