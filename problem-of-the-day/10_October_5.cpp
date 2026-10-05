// problem 856: Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses/

#include <iostream>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};

int main() {
    Solution solution;
    std::string input = "(()(()))";
    int output = solution.scoreOfParentheses(input);

    std::cout << "Score of parentheses: " << output << std::endl;



    std::string input2 = "()()";
    int output2 = solution.scoreOfParentheses(input2);
    std::cout << "Score of parentheses: " << output2 << std::endl;

    std::string input3 = "((()))";
    int output3 = solution.scoreOfParentheses(input3);
    std::cout << "Score of parentheses: " << output3 << std::endl;
    return 0;
}