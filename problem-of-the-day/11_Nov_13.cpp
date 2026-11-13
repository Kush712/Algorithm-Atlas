// problem name: Count Non-Decreasing Subarrays After K Operations
// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& A, long long k) {
        reverse(A.begin(), A.end());
        long long res = 0;
        deque<int> q;
        for (int j = 0, i = 0; j < A.size(); ++j) {
            while (!q.empty() && A[q.back()] < A[j]) {
                int r = q.back();
                q.pop_back();
                int l = q.empty() ? i - 1 : q.back();
                k -= 1L * (r - l) * (A[j] - A[r]);
            }
            q.push_back(j);
            while (k < 0) {
                k += A[q.front()] - A[i];
                if (q.front() == i) {
                    q.pop_front();
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, 2, 3, 4, 5};
    long long k = 3;
    long long result = solution.countNonDecreasingSubarrays(A, k);
    cout << "Count of non-decreasing subarrays after " << k << " operations: " << result << endl;

    vector<int> A2 = {5, 4, 3, 2, 1};
    long long k2 = 10;
    long long result2 = solution.countNonDecreasingSubarrays(A2, k2);
    cout << "Count of non-decreasing subarrays after " << k2 << " operations: " << result2 << endl;

    vector<int> A3 = {1, 3, 2, 4, 5};
    long long k3 = 5;
    long long result3 = solution.countNonDecreasingSubarrays(A3, k3);
    cout << "Count of non-decreasing subarrays after " << k3 << " operations: " << result3 << endl;

    return 0;
}