// problem: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int answer = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                ++left;
            }

            if (sum == target) {
                int currentLength = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX) {
                    answer = min(answer,
                                 currentLength + best[left - 1]);
                }

                best[right] = currentLength;
            }

            if (right > 0) {
                best[right] = min(best[right], best[right - 1]);
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 2, 2, 4, 3};
    int target = 3;
    int result = solution.minSumOfLengths(arr, target);
    cout << "Result: " << result << endl; // Output: Result: 2

    vector<int> arr2 = {7, 3, 4, 7};
    int target2 = 7;
    int result2 = solution.minSumOfLengths(arr2, target2);
    cout << "Result: " << result2 << endl; // Output: Result: 2
    return 0;
}