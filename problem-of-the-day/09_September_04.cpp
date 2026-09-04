// problem: 3903. Smallest Stable Index
// https://leetcode.com/problems/smallest-stable-index-i/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int instability;
        for (int i = 0; i < nums.size(); i++) {
            int maxEle = *max_element(begin(nums), begin(nums) + i + 1);
            int minEle = *min_element(begin(nums)+i, end(nums));

            instability = maxEle - minEle;

             if (instability <= k) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 2, 4, 5};
    int k1 = 2;
    int result1 = solution.firstStableIndex(nums1, k1);
    cout << "Smallest stable index: " << result1 << endl;

    vector<int> nums2 = {5, 4, 3, 2, 1};
    int k2 = 3;
    int result2 = solution.firstStableIndex(nums2, k2);
    cout << "Smallest stable index: " << result2 << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    int k3 = 0;
    int result3 = solution.firstStableIndex(nums3, k3);
    cout << "Smallest stable index: " << result3 << endl;

    return 0;
}