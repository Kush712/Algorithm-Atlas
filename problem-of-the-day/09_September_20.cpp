// problem: 3498. Reverse Degree of a String
// https://leetcode.com/problems/reverse-degree-of-a-string/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int revidx = 'z' - s[i - 1] + 1;
            ans += revidx * i;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    string s = "abc";
    int result = solution.reverseDegree(s);
    cout << "Reverse Degree: " << result << endl;

    string s2 = "zaza";
    int result2 = solution.reverseDegree(s2);
    cout << "Reverse Degree: " << result2 << endl;

    return 0;
}