// leetcode problem 3982 Sum of Integers with Maximum Digit Range
// https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int digitRange(int num) {
        int minDig = 9, maxDig = 0;
        while (num > 0) {
            int dig = num % 10;
            minDig = min(minDig, dig);
            maxDig = max(maxDig, dig);
            num /= 10;
        }
        return maxDig - minDig;
    }

    long long sumOfIntegers(vector<int>& nums) {
        int mx = 0;
        long long ans = 0;

        for (int num : nums) {
            int range = digitRange(num);
            if (range > mx) {
                mx = range;
                ans = num;
            } else if (range == mx) {
                ans += num;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5724, 111, 350};
    cout << "Sum of integers with max digit range: " << sol.sumOfIntegers(nums) << endl;

    vector<int> nums2 = {90, 900};
    cout << "Sum of integers with max digit range: " << sol.sumOfIntegers(nums2) << endl;

    vector<int> nums3 = {19, 28, 37, 46};
    cout << "Sum of integers with max digit range: " << sol.sumOfIntegers(nums3) << endl;

    return 0;
}
