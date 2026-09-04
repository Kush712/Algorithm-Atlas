// leetcode problem 3471 Find the Largest Almost Missing Integer
// https://leetcode.com/problems/find-the-largest-almost-missing-integer/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            int ans = -1;
            for (auto& p : freq) {
                if (p.second == 1) {
                    ans = max(ans, p.first);
                }
            }
            return ans;
        }

        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 9, 2, 1, 7};
    int k = 3;
    cout << "Largest almost missing integer: " << sol.largestInteger(nums, k) << endl;

    vector<int> nums2 = {3, 9, 7, 2, 1, 7};
    int k2 = 4;
    cout << "Largest almost missing integer: " << sol.largestInteger(nums2, k2) << endl;

    vector<int> nums3 = {1, 2, 3};
    int k3 = 1;
    cout << "Largest almost missing integer: " << sol.largestInteger(nums3, k3) << endl;

    return 0;
}
