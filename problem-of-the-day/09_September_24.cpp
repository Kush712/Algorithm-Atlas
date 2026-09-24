// problem: 3550. Smallest Index With Equal Value
// https://leetcode.com/problems/smallest-index-with-equal-value/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int smallest = -1;

        for (int i = 0; i < n; i++) {
            int data = nums[i];
            int sum = 0;
            while (data > 0) {
                sum += data % 10;
                data /= 10;
            }

            if (sum == i) {
                smallest = i;
                break;
            }
        }
        return smallest;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {18, 29, 38, 47, 56};
    int result = solution.smallestIndex(nums);
    cout << "Smallest Index With Equal Value: " << result << endl;

    vector<int> nums2 = {10, 20, 30, 40, 50};
    int result2 = solution.smallestIndex(nums2);
    cout << "Smallest Index With Equal Value: " << result2 << endl;

    vector<int> nums3 = {0, 1, 2, 3, 4};
    int result3 = solution.smallestIndex(nums3);
    cout << "Smallest Index With Equal Value: " << result3 << endl;

    return 0;
}