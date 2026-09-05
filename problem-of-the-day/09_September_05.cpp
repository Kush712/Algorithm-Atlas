// problem: 3904. Smallest Stable Index II
// https://leetcode.com/problems/smallest-stable-index-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        int maxEle = nums[0];

        for (int i = 0; i < n; i++) {
            maxEle = max(maxEle, nums[i]);

            if (maxEle - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 4, 5};
    int k = 2;
    int result = solution.firstStableIndex(nums, k);
    cout << "The first stable index is: " << result << endl;

    vector<int> nums2 = {5, 4, 3, 2, 1};
    int k2 = 1;
    int result2 = solution.firstStableIndex(nums2, k2);
    cout << "The first stable index is: " << result2 << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,77,927, 1000};
    int k3 = 10;
    int result3 = solution.firstStableIndex(nums3, k3);
    cout << "The first stable index is: " << result3 << endl;

    return 0;
}