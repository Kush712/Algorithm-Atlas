// leetcode problem 2029 Stone Game IX
// https://leetcode.com/problems/stone-game-ix/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int s : stones) {
            cnt[s % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

int main() {
    Solution sol;
    vector<int> stones = {2, 1};
    cout << (sol.stoneGameIX(stones) ? "Alice wins" : "Bob wins") << endl;

    vector<int> stones2 = {2};
    cout << (sol.stoneGameIX(stones2) ? "Alice wins" : "Bob wins") << endl;

    vector<int> stones3 = {5, 1, 2, 4, 3};
    cout << (sol.stoneGameIX(stones3) ? "Alice wins" : "Bob wins") << endl;

    vector<int> stones4 = {3, 3, 3, 3};
    cout << (sol.stoneGameIX(stones4) ? "Alice wins" : "Bob wins") << endl;

    return 0;
}
