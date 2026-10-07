// leet code problem 301 : Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses/description/    

#include<iostream>
#include<vector>    
#include<unordered_set> 

using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> st;
    int max_len;

    void solve(string& s, int i, string& curr, int count) {
        if (count < 0) {
            return;
        }

        if (i == n) {
            if (count == 0) {
                if (curr.length() > max_len) {
                    max_len = curr.length();
                    st.clear();
                }

                if (curr.length() == max_len) {
                    st.insert(curr);
                }
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(s, i + 1, curr, count);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s, i + 1, curr, count + (s[i] == '(' ? 1 : -1));

        curr.pop_back();

        solve(s, i + 1, curr, count);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        st.clear();
        max_len = 0;

        string curr = "";

        solve(s, 0, curr, 0);

        return vector<string>(st.begin(), st.end());
    }
};

int main() {
    Solution solution;
    string input = "()())()";
    vector<string> output = solution.removeInvalidParentheses(input);

    cout << "Valid parentheses combinations: " << endl;
    for (const string& str : output) {
        cout << str << endl;
    }

    string input2 = "(a)())()"; 
    vector<string> output2 = solution.removeInvalidParentheses(input2);
    cout << "Valid parentheses combinations for input2: " << endl;  
    for (const string& str : output2) { 
        cout << str << endl;
    }

    return 0;
}