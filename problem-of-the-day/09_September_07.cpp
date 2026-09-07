// problem 940 : distinct subsequences II
// https://leetcode.com/problems/distinct-subsequences-ii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;

    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> dp(n+1), pos(26);

        for(int i=1;i<=n;i++)
        {
            int c=s[i-1]-'a';

            dp[i]=(2*dp[i-1]+1)%mod;

            if(pos[c]!=0)
                dp[i]=(dp[i]-(dp[pos[c]-1]+1)+mod)%mod;

            pos[c]=i;
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "abc";
    int result1 = solution.distinctSubseqII(s1);
    cout << "Distinct subsequences of \"" << s1 << "\": " << result1 << endl;

    // Test case 2
    string s2 = "aba";
    int result2 = solution.distinctSubseqII(s2);
    cout << "Distinct subsequences of \"" << s2 << "\": " << result2 << endl;

    // Test case 3
    string s3 = "aaa";
    int result3 = solution.distinctSubseqII(s3);
    cout << "Distinct subsequences of \"" << s3 << "\": " << result3 << endl;

    return 0;
}