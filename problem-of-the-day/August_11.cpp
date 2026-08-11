#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> seen(nums.begin(), nums.end());

        int answer = sum;

        while (seen.count(answer)) {
            answer++;
        }

        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 5, 6};

    int missing = solution.missingInteger(nums);
    cout << "The smallest missing integer is: " << missing << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    missing = solution.missingInteger(nums2);
    cout << "The smallest missing integer is: " << missing << endl;

    vector<int> nums3 = {2, 3, 4, 5};
    missing = solution.missingInteger(nums3);
    cout << "The smallest missing integer is: " << missing << endl;

    return 0;
}