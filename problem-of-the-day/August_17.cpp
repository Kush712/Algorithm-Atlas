// leetcode problem 1563 Stone Game V
// https://leetcode.com/problems/stone-game-v/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int t[501][501];
    vector<int> prefix;

    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(vector<int>& stones, int l, int r) {
        if (l == r) return 0;
        if (t[l][r] != -1) return t[l][r];

        int result = 0;

        for (int i = l; i < r; i++) {
            int leftSum = getSum(l, i);
            int rightSum = getSum(i + 1, r);

            if (leftSum < rightSum) {
                result = max(result, leftSum + solve(stones, l, i));
            } else if (rightSum < leftSum) {
                result = max(result, rightSum + solve(stones, i + 1, r));
            } else {
                result = max(result, leftSum + solve(stones, l, i));
                result = max(result, rightSum + solve(stones, i + 1, r));
            }
        }

        return t[l][r] = result;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        memset(t, -1, sizeof(t));
        return solve(stoneValue, 0, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> stones = {6, 2, 3, 4, 5, 5};
    cout << "Stone Game V result: " << sol.stoneGameV(stones) << endl;

    vector<int> stones2 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Stone Game V result: " << sol.stoneGameV(stones2) << endl;

    vector<int> stones3 = {4};
    cout << "Stone Game V result: " << sol.stoneGameV(stones3) << endl;

    return 0;
}
