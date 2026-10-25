// leetcode problem 3983 Subsequence After One Replacement
// https://leetcode.com/problems/subsequence-after-one-replacement/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) return false;

        // suffix[j] = earliest position in s (from the right) where t[j..m-1] can be matched
        vector<int> suf(m + 1, n);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (s[i] == t[j]) {
                suf[j] = i;
                j--;
            }
        }

        // Check if t is already a subsequence
        if (j < 0) return true;

        // Try replacing each position in t
        j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s[i] == t[j]) {
                j++;
            } else {
                // Try replacing t[j] with s[i]
                if (j + 1 >= m || (suf[j + 1] != n && suf[j + 1] > i)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "abcde";
    string t1 = "axe";
    cout << "Can make subsequence: " << (sol.canMakeSubsequence(s1, t1) ? "true" : "false") << endl;

    string s2 = "abcde";
    string t2 = "aec";
    cout << "Can make subsequence: " << (sol.canMakeSubsequence(s2, t2) ? "true" : "false") << endl;

    string s3 = "abc";
    string t3 = "ab";
    cout << "Can make subsequence: " << (sol.canMakeSubsequence(s3, t3) ? "true" : "false") << endl;

    return 0;
}
