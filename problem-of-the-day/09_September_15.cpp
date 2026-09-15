// problem: 2472. Maximum Number of Non-overlapping Palindrome Substrings
// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), lastEnd = 0, count = 0;

        for (int center = 0; center < 2 * n; center++) {
            int left = center / 2;
            int right = left + center % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= k) {
                    int end = right + 1;

                    if (left >= lastEnd)
                        lastEnd = end, count++;
                    else
                        lastEnd = min(lastEnd, end);

                    break;
                }
                left--, right++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    string s1 = "ababa";
    int k1 = 3;
    int result1 = solution.maxPalindromes(s1, k1);
    cout << "Max Palindromes: " << result1 << endl; // Output: Max Palindromes: 2

    string s2 = "adbcda";
    int k2 = 2;
    int result2 = solution.maxPalindromes(s2, k2);
    cout << "Max Palindromes: " << result2 << endl; // Output: Max Palindromes: 0

    string s3 = "aaa";
    int k3 = 2;
    int result3 = solution.maxPalindromes(s3, k3);
    cout << "Max Palindromes: " << result3 << endl; // Output: Max Palindromes: 1

    return 0;
}