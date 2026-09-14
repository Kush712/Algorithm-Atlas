// problem: 836. Rectangle Overlap
// https://leetcode.com/problems/rectangle-overlap/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        if (rec2[0] >= rec1[2]) return false;
        if (rec2[1] >= rec1[3]) return false;
        if (rec2[2] <= rec1[0]) return false;
        if (rec2[3] <= rec1[1]) return false;

        return true;
    }

};

int main() {
    Solution solution;
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    bool result = solution.isRectangleOverlap(rec1, rec2);
    cout << "Is Rectangle Overlap: " << (result ? "true" : "false") << endl; // Output: Is Rectangle Overlap: true
    
    vector<int> rec3 = {0, 0, 1, 1};
    vector<int> rec4 = {1, 0, 2, 1};
    result = solution.isRectangleOverlap(rec3, rec4);
    cout << "Is Rectangle Overlap: " << (result ? "true" : "false") << endl; // Output: Is Rectangle Overlap: false

    vector<int> rec5 = {0, 0, 1, 1};
    vector<int> rec6 = {0, 1, 1, 2};
    result = solution.isRectangleOverlap(rec5, rec6);   
    cout << "Is Rectangle Overlap: " << (result ? "true" : "false") << endl; // Output: Is Rectangle Overlap: false
    
    return 0;
}