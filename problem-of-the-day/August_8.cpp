// leetcode problem 3302 Find The Lexicographically Smallest Valid Sequence
// https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m, -1);
        vector<int> ans;

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
        }

        j = 0;
        bool used = false;

        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!used && (j == m - 1 || 
                     (suf[j + 1] != -1 && i < suf[j + 1]))) {
                ans.push_back(i);
                j++;
                used = true;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};

int main() {
    Solution s;
    string word1 = "abcde";
    string word2 = "ace";
    vector<int> result = s.validSequence(word1, word2);

    if (!result.empty()) {
        cout << "Valid sequence indices: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No valid sequence found." << endl;
    }

    string word3 = "abcde";
    string word4 = "aec";   
    vector<int> result2 = s.validSequence(word3, word4);

    if (!result2.empty()) {
        cout << "Valid sequence indices: ";
        for (int index : result2) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No valid sequence found." << endl;
    }

    string word5 = "abcde";
    string word6 = "abcde";
    vector<int> result3 = s.validSequence(word5, word6);

    if (!result3.empty()) {
        cout << "Valid sequence indices: ";
        for (int index : result3) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No valid sequence found." << endl;
    }   

    return 0;
}   