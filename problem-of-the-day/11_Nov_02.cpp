// problem name : Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        int moves = 0;

        for (int i = 0; i < n; i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int result = solution.minMoves2(nums);
    cout << "Minimum moves to equal array elements II: " << result << endl; // Output: 2

    vector<int> nums2 = {1, 0, 0, 8, 6};
    int result2 = solution.minMoves2(nums2);
    cout << "Minimum moves to equal array elements II: " << result2 << endl; // Output: 14

    vector<int> nums3 = {1, 10, 2, 9};
    int result3 = solution.minMoves2(nums3);
    cout << "Minimum moves to equal array elements II: " << result3 << endl; // Output: 16

    return 0;
}