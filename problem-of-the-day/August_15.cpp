// leetcode problem 3702 Longest Subsequence With Non-Zero Bitwise XOR
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool hasNonZero = false;

        for (int i = 0; i < n; i++) {
            totalXor ^= nums[i];
            if (nums[i] != 0) {
                hasNonZero = true;
            }
        }

        if (totalXor != 0) {
            return n;
        }

        if (!hasNonZero) {
            return 0;
        }

        return n - 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << "Longest subsequence: " << sol.longestSubsequence(nums) << endl;

    vector<int> nums2 = {4, 4, 4};
    cout << "Longest subsequence: " << sol.longestSubsequence(nums2) << endl;

    vector<int> nums3 = {0, 0, 0};
    cout << "Longest subsequence: " << sol.longestSubsequence(nums3) << endl;

    vector<int> nums4 = {1, 5, 3, 7};
    cout << "Longest subsequence: " << sol.longestSubsequence(nums4) << endl;

    return 0;
}
