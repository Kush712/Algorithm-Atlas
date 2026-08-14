// leetcode problem: 3090 maximum-length-of-a-substring-with-at-most-two-distinct-characters
// https://leetcode.com/problems/maximum-length-of-a-substring-with-at-most-two-distinct-characters/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        int ans = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            freq[s[j] - 'a']++;

            while (i < j && freq[s[j] - 'a'] > 2) {
                freq[s[i] - 'a']--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "abcabcabc";
    int result = solution.maximumLengthSubstring(s);
    cout << "Maximum length of substring: " << result << endl;

    string s2 = "aabbcc";
    int result2 = solution.maximumLengthSubstring(s2);
    cout << "Maximum length of substring: " << result2 << endl;

    string s3 = "aaabbbccc";
    int result3 = solution.maximumLengthSubstring(s3);
    cout << "Maximum length of substring: " << result3 << endl;
    return 0;
}