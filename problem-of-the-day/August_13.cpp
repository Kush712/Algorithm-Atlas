// leetcode problem 2213 Longest Substring of One Repeating Character
// https://leetcode.com/problems/longest-substring-of-one-repeating-character/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Node {
        int pre, suf, mx, len;
        char lc, rc;
    };

    vector<Node> tree;
    string s;

    Node merge(Node& l, Node& r) {
        Node res;
        res.len = l.len + r.len;
        res.lc = l.lc;
        res.rc = r.rc;

        res.pre = l.pre;
        if (l.pre == l.len && l.rc == r.lc) {
            res.pre = l.len + r.pre;
        }

        res.suf = r.suf;
        if (r.suf == r.len && r.lc == l.rc) {
            res.suf = r.len + l.suf;
        }

        res.mx = max(l.mx, r.mx);
        if (l.rc == r.lc) {
            res.mx = max(res.mx, l.suf + r.pre);
        }
        res.mx = max(res.mx, max(res.pre, res.suf));

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            s[idx] = c;
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, end, idx, c);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        this->s = s;
        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> result;
        for (int i = 0; i < (int)queryCharacters.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result.push_back(tree[1].mx);
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "babacc";
    string queryChars = "bcb";
    vector<int> queryIndices = {1, 3, 3};
    vector<int> result = sol.longestRepeating(s, queryChars, queryIndices);

    cout << "Longest repeating after each query: ";
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    string s2 = "abyzz";
    string queryChars2 = "aa";
    vector<int> queryIndices2 = {2, 1};
    vector<int> result2 = sol.longestRepeating(s2, queryChars2, queryIndices2);

    cout << "Longest repeating after each query: ";
    for (int r : result2) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
