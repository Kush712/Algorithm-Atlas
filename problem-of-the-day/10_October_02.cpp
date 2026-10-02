// problem: 22. Generate Parentheses    
// https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getParenthesis(0, 0, "", n, res);
        return res;
    }

    void getParenthesis(int open, int close, string s, int n, vector<string>& res) {
        if(s.length() == 2 * n) {
            res.push_back(s);
        }

        if(open < n) {
            getParenthesis(open + 1, close, s + "(", n, res);
        }

        if(close < open) {
            getParenthesis(open, close + 1, s + ")", n, res);
        }
    }
};


int main() {
    Solution solution;
    int n = 3; // Example input
    vector<string> result = solution.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":\n";
    for(const string& s : result) {
        cout << s << endl;
    }

    return 0;
}   