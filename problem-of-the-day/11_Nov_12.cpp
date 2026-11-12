// problem name: Longest Strictly Increasing or Strictly Decreasing Subarray                
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

#include <iostream>
#include <vector>   
#include <algorithm>    

using namespace std;    

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr_count = 1;
        int decr_count = 1;
        int max1 = 1;

        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                incr_count++;
                decr_count = 1;
            }
            else if(nums[i] < nums[i-1]) {
                decr_count++;
                incr_count = 1;
            }
            else {
                incr_count = 1;
                decr_count = 1;
            }

            max1 = max(max1, max(incr_count, decr_count));
        }

        return max1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 2, 1, 0, -1, -2};
    int result = solution.longestMonotonicSubarray(nums);
    cout << "Length of the longest strictly increasing or strictly decreasing subarray: " << result << endl;
    

    vector<int> nums2 = {1, 2, 3, 2, 1, 0, -1, -2};
    int result2 = solution.longestMonotonicSubarray(nums2);   
    cout << "Length of the longest strictly increasing or strictly decreasing subarray: " << result2 << endl;

    vector<int> nums3 = {5, 4, 3, 2, 1};   
    int result3 = solution.longestMonotonicSubarray(nums3);   
    cout << "Length of the longest strictly increasing or strictly decreasing subarray: " << result3 << endl;

    return 0;

}   