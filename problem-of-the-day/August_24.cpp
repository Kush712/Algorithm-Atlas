// leetcode problem 3987 Minimum Total Cost to Process All Elements
// https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int minTotalCost(vector<int>& nums, int k) {
        long long resources = k;
        long long opCount = 0;
        long long totalCost = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            while (resources < nums[i]) {
                resources += k;
                opCount++;
                totalCost = (totalCost + opCount) % MOD;
            }
            resources -= nums[i];
        }

        return (int)totalCost;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 5};
    int k = 4;
    cout << "Minimum total cost: " << sol.minTotalCost(nums, k) << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    cout << "Minimum total cost: " << sol.minTotalCost(nums2, k2) << endl;

    vector<int> nums3 = {10};
    int k3 = 5;
    cout << "Minimum total cost: " << sol.minTotalCost(nums3, k3) << endl;

    vector<int> nums4 = {1, 1, 1, 1};
    int k4 = 2;
    cout << "Minimum total cost: " << sol.minTotalCost(nums4, k4) << endl;

    return 0;
}
