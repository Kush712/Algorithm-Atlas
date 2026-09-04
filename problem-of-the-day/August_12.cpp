// leetcode problem 3975 Filter Occupied Intervals
// https://leetcode.com/problems/filter-occupied-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        for (auto& interval : occupiedIntervals) {
            if (!merged.empty() && interval[0] <= merged.back()[1] + 1) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }

        vector<vector<int>> result;
        for (auto& interval : merged) {
            if (interval[1] < freeStart || interval[0] > freeEnd) {
                result.push_back(interval);
            } else {
                if (interval[0] < freeStart) {
                    result.push_back({interval[0], freeStart - 1});
                }
                if (interval[1] > freeEnd) {
                    result.push_back({freeEnd + 1, interval[1]});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 5}, {3, 8}, {12, 15}};
    int freeStart = 4, freeEnd = 10;
    vector<vector<int>> result = sol.filterIntervals(intervals, freeStart, freeEnd);

    cout << "Filtered intervals: ";
    for (auto& r : result) {
        cout << "[" << r[0] << "," << r[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1, 3}, {5, 7}, {9, 11}};
    int freeStart2 = 4, freeEnd2 = 8;
    vector<vector<int>> result2 = sol.filterIntervals(intervals2, freeStart2, freeEnd2);

    cout << "Filtered intervals: ";
    for (auto& r : result2) {
        cout << "[" << r[0] << "," << r[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals3 = {{1, 1}, {2, 2}, {3, 3}};
    int freeStart3 = 2, freeEnd3 = 2;
    vector<vector<int>> result3 = sol.filterIntervals(intervals3, freeStart3, freeEnd3);

    cout << "Filtered intervals: ";
    for (auto& r : result3) {
        cout << "[" << r[0] << "," << r[1] << "] ";
    }
    cout << endl;

    return 0;
}
