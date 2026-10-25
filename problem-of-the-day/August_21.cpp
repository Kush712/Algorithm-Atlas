// leetcode problem 3984 Divisible Game
// https://leetcode.com/problems/divisible-game/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        long long bestDiff = -1e18;
        int bestK = 2;

        for (int k = 2; k <= *max_element(nums.begin(), nums.end()); k++) {
            long long maxDiff = -1e18;
            long long currDiff = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] % k == 0) {
                    currDiff += nums[i];
                } else {
                    currDiff -= nums[i];
                }
                maxDiff = max(maxDiff, currDiff);
                if (currDiff < 0) currDiff = 0;
            }

            if (maxDiff > bestDiff || (maxDiff == bestDiff && k < bestK)) {
                bestDiff = maxDiff;
                bestK = k;
            }
        }

        return (int)((bestDiff % MOD * (bestK % MOD)) % MOD);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 6, 8};
    cout << "Divisible Game result: " << sol.divisibleGame(nums) << endl;

    vector<int> nums2 = {2, 1, 2};
    cout << "Divisible Game result: " << sol.divisibleGame(nums2) << endl;

    vector<int> nums3 = {3, 6, 9, 12};
    cout << "Divisible Game result: " << sol.divisibleGame(nums3) << endl;

    return 0;
}
