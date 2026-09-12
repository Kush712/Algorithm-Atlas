// problem name: Maximum Score of Non-Overlapping Intervals
// https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n)
            return Node();

        if (t[i][k].score != -1)
            return t[i][k];

        int weight = intervals[i][2];
        int idx    = intervals[i][3];
        int j      = nextIdx[i];

        //skip interval i
        Node skip = solve(intervals, i + 1, k);

        //take interval i
        Node temp = solve(intervals, j, k - 1);
        Node take;
        take.score = temp.score + weight;
        take.idxs  = temp.idxs;
        take.idxs.push_back(idx);
        sort(begin(take.idxs), end(take.idxs));

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

        const int K = 4;
        t.assign(n + 1, vector<Node>(K + 1));

        return solve(intervals, 0, K).idxs;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3, 4}, {2, 5, 2}, {4, 6, 4}, {6, 7, 1}};
    vector<int> result = solution.maximumWeight(intervals);
    
    cout << "Selected interval indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}