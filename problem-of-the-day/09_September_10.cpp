// problem: 2265. Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

#include<iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int result;

    pair<int,int> solve(TreeNode* root) {
        if(!root)
            return {0, 0};

        auto p1 = solve(root->left);
        auto p2 = solve(root->right);

        int totalSum = p1.first + p2.first + root->val;
        int totalCount = p1.second + p2.second + 1;

        int totalAverage = totalSum / totalCount;

        if(totalAverage == root->val)
            result++;

        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        solve(root);

        return result;
    }
};

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    int count = solution.averageOfSubtree(root);
    cout << "Count of nodes equal to average of subtree: " << count << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
