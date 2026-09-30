// problem name : 1111. Maximum Nesting Depth of Two Valid Parentheses Strings  
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings

#include <iostream>
#include <vector>

using namespace std;

class Solution { 
public: 
    vector<int> maxDepthAfterSplit(string seq) { 
        vector<int> ans(seq.size());
        int depth = 0;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ++depth;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                --depth;
            }
        }
        return ans;
    } 
};

int main() {
    Solution solution;
    string seq = "(()())";
    vector<int> result = solution.maxDepthAfterSplit(seq);
    
    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
