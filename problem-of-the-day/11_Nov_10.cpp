// problem name: Minimum Cost to Climb Stairs II    
//https://leetcode.com/problems/climbing-stairs-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int i, int n, vector<int>& costs) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int cost = INT_MAX;

        int j = i + 1;
        if (j <= n) {
            cost = solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i);
        }

        j = i + 2;
        if (j <= n) {
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));
        }

        j = i + 3;
        if (j <= n) {
            cost = min(cost, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));
        }

        return dp[i] = cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n + 1, -1);
        return solve(0, n, costs);
    }
};

int main() {
    Solution solution;
    vector<int> costs = {1, 2, 3, 4, 5};
    int n = costs.size();
    int result = solution.climbStairs(n, costs);
    cout << "Minimum cost to climb stairs: " << result << endl;

    vector<int> costs2 = {10, 15, 20};
    int n2 = costs2.size(); 
    int result2 = solution.climbStairs(n2, costs2);
    cout << "Minimum cost to climb stairs: " << result2 << endl;

    vector<int> costs3 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};  
    int n3 = costs3.size();
    int result3 = solution.climbStairs(n3, costs3); 
    cout << "Minimum cost to climb stairs: " << result3 << endl;

    return 0;
}