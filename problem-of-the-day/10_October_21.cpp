// problem: 3863. Minimum Operations to Sort a String
// https://leetcode.com/problems/minimum-operations-to-sort-a-string/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {

        int mini = s[0] - 'a';
        int maxi = s.back() - 'a';

        for (char c : s) {
            mini = min(mini, c - 'a');
            maxi = max(maxi, c - 'a');
        }

        if (s.size() == 1) {
            return 0;
        }

        if (s.size() == 2) {
            return s[0] <= s[1] ? 0 : -1;
        }

        int ans = 0;
        int n = s.size();

        int minCount = 0;
        int maxCount = 0;

        for (char c : s) {
            if (c - 'a' == mini) {
                minCount++;
            }
            if (c - 'a' == maxi) {
                maxCount++;
            }
        }

        if (mini != s[0] - 'a') {
            ans++;
        }

        if (maxi != s.back() - 'a') {

            ans++;
        }

        if (ans == 0) {

            string a = s;
            sort(a.begin(),a.end());

            for(int i = 1;i<n-1;i++){
                if(a[i]!=s[i]){
                    return 1;
                }
            }
        }

        if (s[0] - 'a' == maxi && s.back() - 'a' == mini) {
            if (minCount == 1 && maxCount == 1) {
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "cba";
    int result = solution.minOperations(s);
    cout << "Minimum operations to sort the string: " << result << endl;
    return 0;
}