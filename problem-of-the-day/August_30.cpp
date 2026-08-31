// Problem: Removing Minimum and Maximum From Array
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int max_idx = max_element(begin(nums),end(nums)) - begin(nums);
        int min_idx =min_element(begin(nums),end(nums)) - begin(nums);;

        int left = min(max_idx,min_idx);
        int right = max(max_idx,min_idx);

        int ans1 = left + 1 + n - right;
        int ans2 = right + 1;
        int ans3 = n - left ;

        return min({ans1,ans2,ans3});
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    int result = solution.minimumDeletions(nums);
    cout << "Minimum deletions: " << result << endl;

    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    int result2 = solution.minimumDeletions(nums2);
    cout << "Minimum deletions: " << result2 << endl;

    vector<int> nums3 = {101};
    int result3 = solution.minimumDeletions(nums3);
    cout << "Minimum deletions: " << result3 << endl;
    
    return 0;
}