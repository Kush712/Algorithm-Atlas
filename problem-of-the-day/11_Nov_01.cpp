// problem: 453. Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minNum = *min_element(nums.begin(), nums.end());
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        return sum - n * minNum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int result = solution.minMoves(nums);
    cout << "Minimum moves to equal array elements: " << result << endl; // Output: 3

    vector<int> nums2 = {1, 1, 1};
    int result2 = solution.minMoves(nums2);
    cout << "Minimum moves to equal array elements: " << result2 << endl; // Output: 0

    vector<int> nums3 = {1, 2, 3, 4};
    int result3 = solution.minMoves(nums3);
    cout << "Minimum moves to equal array elements: " << result3 << endl; // Output: 6


    return 0;
}