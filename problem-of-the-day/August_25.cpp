// Problem: 3718. Smallest Missing Multiple of K
//https://leetcode.com/problems/smallest-missing-multiple-of-k/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int samp = k;
        for (int i = 0; i < n; i++) {
            int semp2 = k;
            if (samp == nums[i]) {
                samp = samp + semp2;
            }
        }
        return samp;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 6, 9, 12};
    int k = 3;
    int result = solution.missingMultiple(nums, k);
    cout << "Smallest Missing Multiple of " << k << ": " << result << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    int result2 = solution.missingMultiple(nums2, k2);
    cout << "Smallest Missing Multiple of " << k2 << ": " << result2 << endl;

    vector<int> nums3 = {5, 10, 15};
    int k3 = 5;
    int result3 = solution.missingMultiple(nums3, k3);
    cout << "Smallest Missing Multiple of " << k3 << ": " << result3 << endl;

    vector<int> nums4 = {2, 4, 6, 8};
    int k4 = 2;
    int result4 = solution.missingMultiple(nums4, k4);
    cout << "Smallest Missing Multiple of " << k4 << ": " << result4 << endl;
    
    return 0;
}