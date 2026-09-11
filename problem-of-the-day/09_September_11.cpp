// problem: 3483. Count of Unique Even Three-Digit Numbers
// https://leetcode.com/problems/unique-3-digit-even-numbers/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){

                    int data1 = nums[i] * 100 + nums[j] * 10 + nums[k];
                    int data2 = nums[i] * 100 + nums[k] * 10 + nums[j];
                    int data3 = nums[j] * 100 + nums[i] * 10 + nums[k];
                    int data4 = nums[j] * 100 + nums[k] * 10 + nums[i];
                    int data5 = nums[k] * 100 + nums[i] * 10 + nums[j];
                    int data6 = nums[k] * 100 + nums[j] * 10 + nums[i];

                    if(nums[i] != 0 && data1 % 2 == 0)
                        set.insert(data1);

                    if(nums[i] != 0 && data2 % 2 == 0)
                        set.insert(data2);

                    if(nums[j] != 0 && data3 % 2 == 0)
                        set.insert(data3);

                    if(nums[j] != 0 && data4 % 2 == 0)
                        set.insert(data4);

                    if(nums[k] != 0 && data5 % 2 == 0)
                        set.insert(data5);

                    if(nums[k] != 0 && data6 % 2 == 0)
                        set.insert(data6);
                }
            }
        }

        return set.size();
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {1, 2, 3, 4};
    int count = solution.totalNumbers(nums);
    cout << "Count of unique even three-digit numbers: " << count << std::endl;

    vector<int> nums2 = {0, 1, 2};
    int count2 = solution.totalNumbers(nums2);
    cout << "Count of unique even three-digit numbers: " << count2 << std::endl;

    vector<int> nums3 = {0, 2, 2};
    int count3 = solution.totalNumbers(nums3);
    cout << "Count of unique even three-digit numbers: " << count3 << std:: endl;

    return 0;
}