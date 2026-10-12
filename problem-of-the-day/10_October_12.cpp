// problem name 2897 : apply-operations-on-array-to-maximize-sum-of-squares
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int bits[31] = {};

        for (int x : nums)
            for (int b = 0; b < 31; b++)
                if (x & (1 << b)) bits[b]++;

        long long ans = 0;

        while (k--) {
            long long x = 0;
            for (int b = 0; b < 31; b++)
                if (bits[b] > 0)
                    x |= (1LL << b), bits[b]--;

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int result = solution.maxSum(nums, k);
    cout << "Max sum of squares: " << result << endl;
    return 0;
}