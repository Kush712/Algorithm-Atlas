// problem: 835. Image Overlap
// https://leetcode.com/problems/image-overlap/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A, B;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) A.emplace_back(i, j);
                if (img2[i][j] == 1) B.emplace_back(i, j);
            }
        }
        vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));
        int best = 0;
        for (auto& a : A) {
            for (auto& b : B) {
                int dx = b.first - a.first + n;
                int dy = b.second - a.second + n;
                best = max(best, ++cnt[dx][dy]);
            }
        }
        return best;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    int result = solution.largestOverlap(img1, img2);
    cout << "Largest Overlap: " << result << endl; // Output: Largest Overlap: 3
    return 0;
}