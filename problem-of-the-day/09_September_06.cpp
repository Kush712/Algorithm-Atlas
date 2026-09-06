// problem: 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[1001][1001];

    int solve(string& s, string& t, int m, int n) {
        if (n == 0)
            return dp[m][n] = 1;

        if (m == 0)
            return dp[m][n] = 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (s[m - 1] == t[n - 1])
            return dp[m][n] = solve(s, t, m - 1, n) +
                               solve(s, t, m - 1, n - 1);
        else
            return dp[m][n] = solve(s, t, m - 1, n);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n)
            return 0;

        memset(dp, -1, sizeof(dp));

        return solve(s, t, m, n);
    }
};

int main() {
    Solution solution;

    string s = "rabbbit";
    string t = "rabbit";
    int result = solution.numDistinct(s, t);
    cout << "The number of distinct subsequences is: " << result << endl;

    string s2 = "babgbag";
    string t2 = "bag";
    int result2 = solution.numDistinct(s2, t2);
    cout << "The number of distinct subsequences is: " << result2 << endl;

    string s3 = "abcde";
    string t3 = "ace";
    int result3 = solution.numDistinct(s3, t3);
    cout << "The number of distinct subsequences is: " << result3 << endl;

    return 0;
}