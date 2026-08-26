// Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
//https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int one = 0;
        string ans = "";

        for(int right = 0; right < n; right++) {
            if(s[right] == '1')
                one++;

            while(one > k) {
                if(s[left] == '1')
                    one--;
                left++;
            }

            while(one == k && s[left] == '0')
                left++;

            if(one == k) {
                string curr = s.substr(left, right-left+1);

                if(ans == "" || curr.size() < ans.size() ||
                   (curr.size() == ans.size() && curr < ans))
                    ans = curr;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "110100110";
    int k = 2;
    string result = solution.shortestBeautifulSubstring(s, k);
    cout << "Shortest Beautiful Substring: " << result << endl;

    string s2 = "000111000";
    int k2 = 3;
    string result2 = solution.shortestBeautifulSubstring(s2, k2);
    cout << "Shortest Beautiful Substring: " << result2 << endl;

    string s3 = "1010101";
    int k3 = 1;
    string result3 = solution.shortestBeautifulSubstring(s3, k3);
    cout << "Shortest Beautiful Substring: " << result3 << endl;

    return 0;
}