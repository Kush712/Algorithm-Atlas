// Problem: Minimum Operations to Reduce X to Zero
// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i<n; i++){
            totalSum = totalSum + nums[i];
        }

        if (totalSum < x) {
            return -1;
        }


        int target = totalSum - x;

        int left = 0;
        int right = 0;
        int maxLen = -1;
        int sum = 0;

        while(right < n){
            sum = sum + nums[right];

            while(sum > target){
                sum = sum - nums[left];
                left++;
            }

            if(sum == target){
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        if(maxLen == -1){
            return -1;
        }
        
        return n - maxLen;
    }
};
 
int main() {
    Solution solution;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    int result = solution.minOperations(nums, x);
    cout << "Minimum Operations: " << result << endl;

    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;
    int result2 = solution.minOperations(nums2, x2);
    cout << "Minimum Operations: " << result2 << endl;

    return 0;
}