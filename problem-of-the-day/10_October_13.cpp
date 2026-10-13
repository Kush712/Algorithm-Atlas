// problem: 3727. Maximum Alternating Sum of Squares
// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();

        transform(nums.begin(), nums.end(), nums.begin(),
                  [](int x) { return abs(x); });

        sort(nums.begin(), nums.end());

        long long count = nums.size();

        long long i = 0;
        long long j = n - 1;
        long long ans = 0;

        while (j >= i) {
            if (count > 0) {
                ans += (nums[j] * nums[j]);
                j--;
                count--;
            }

            if (count > 0) {
                ans -= (nums[i] * nums[i]);
                i++;
                count--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    long long result = solution.maxAlternatingSum(nums);
    cout << "Maximum Alternating Sum of Squares: " << result << endl;

    vector<int> nums2 = {-1, -2, -3, -4};
    long long result2 = solution.maxAlternatingSum(nums2);
    cout << "Maximum Alternating Sum of Squares: " << result2 << endl;

    vector<int> nums3 = {5, -1, 2, -3};
    long long result3 = solution.maxAlternatingSum(nums3);
    cout << "Maximum Alternating Sum of Squares: " << result3 << endl;
    
    return 0;
}