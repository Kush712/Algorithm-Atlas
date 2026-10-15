// problem name: 2913. Subarrays Distinct Element Sum of Squares I
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                int count = st.size();
                ans += (count * count);
            }
            st.clear();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3};
    int result = solution.sumCounts(nums);
    std::cout << "Sum of Distinct Element Counts Squared: " << result << std::endl;

    std::vector<int> nums2 = {1, 1, 1};
    int result2 = solution.sumCounts(nums2);
    std::cout << "Sum of Distinct Element Counts Squared: " << result2 << std::endl;

    std::vector<int> nums3 = {1, 2, 1, 3};
    int result3 = solution.sumCounts(nums3);
    std::cout << "Sum of Distinct Element Counts Squared: " << result3 << std::endl;

    return 0;
}