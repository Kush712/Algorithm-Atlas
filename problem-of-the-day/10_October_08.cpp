// problem: 1021. Remove Outermost Parentheses  
// https://leetcode.com/problems/remove-outermost-parentheses/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string result = "";
        int count = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(count != 0){
                    result += s[i];
                }
                count++;
            }
            else{
                count--;
                 if(count != 0){
                    result += s[i];
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "(()())(())";
    string result = solution.removeOuterParentheses(s);
    cout << "Result: " << result << endl; // Output: "()()()"

    string s2 = "(()())(())(()(()))";  
    string result2 = solution.removeOuterParentheses(s2);
    cout << "Result: " << result2 << endl; // Output: "()()()()(())"    

    string s3 = "()()";
    string result3 = solution.removeOuterParentheses(s3);
    cout << "Result: " << result3 << endl; // Output: ""
    return 0;
}