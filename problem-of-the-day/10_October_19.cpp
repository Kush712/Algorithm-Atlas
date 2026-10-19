// Problem: 2089. Find Target Indices After Sorting Array
//  https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    std::vector<int> result = solution.targetIndices(nums, target);
    std::cout << "Target Indices: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1, 2, 5, 2, 3};
    int target2 = 3;
    std::vector<int> result2 = solution.targetIndices(nums2, target2);
    std::cout << "Target Indices: ";
    for (int index : result2) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}