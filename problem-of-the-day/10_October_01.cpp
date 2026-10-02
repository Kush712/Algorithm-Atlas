// problem-of-the-day/10_October_01.cpp 
// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            else {
                if (st.empty()) {
                    return false;
                }

                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "{[()]}"; // Example input
    bool result = solution.isValid(s);

    cout << "Is the string \"" << s << "\" valid? " << (result ? "Yes" : "No") << endl;

    return 0;
}