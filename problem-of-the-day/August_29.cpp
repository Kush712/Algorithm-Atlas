//Problem: 2948. Make Array Lexicographically Smaller by Swapping Elements
//https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        vector<int> indices;
        int l = 0;

        indices.push_back(vp[0].second);

        for (int i = 1; i < n; i++) {

            if (vp[i].first - vp[i - 1].first <= limit) {
                indices.push_back(vp[i].second);
            }
            else {
                sort(indices.begin(), indices.end());

                int a = 0;

                for (int j = l; j < i; j++) {
                    nums[indices[a]] = vp[j].first;
                    a++;
                }

                indices.clear();
                indices.push_back(vp[i].second);

                l = i;
            }
        }

        sort(indices.begin(), indices.end());

        int a = 0;

        for (int j = l; j < n; j++) {
            nums[indices[a]] = vp[j].first;
            a++;
        }

        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 1, 2};
    int limit = 1;

    vector<int> result = solution.lexicographicallySmallestArray(nums, limit);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;


    vector<int> nums2 = {5, 4, 3, 2, 1};
    int limit2 = 2;

    vector<int> result2 = solution.lexicographicallySmallestArray(nums2, limit2);

    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;


    vector<int> nums3 = {1, 2, 3, 4, 5};
    int limit3 = 0;

    vector<int> result3 = solution.lexicographicallySmallestArray(nums3, limit3);

    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}