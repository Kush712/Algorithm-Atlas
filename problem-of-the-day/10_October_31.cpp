// problem name : Twisted Mirror Path Count
// https://leetcode.com/problems/twisted-mirror-path-count/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int n;
    int m;
    int UP = 1;
    int LEFT = 0;

    int solve(vector<vector<int>> &grid, int i, int j, int cameFrom)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }

        if (grid[i][j] == 1)
        {
            if (cameFrom == UP)
            {
                return solve(grid, i + 1, j, UP);
            }
            else
            {
                return solve(grid, i, j + 1, LEFT);
            }
        }

        int total = 0;

        total = (total + solve(grid, i + 1, j, UP)) % MOD;
        total = (total + solve(grid, i, j + 1, LEFT)) % MOD;

        return total;
    }

    int uniquePaths(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        return solve(grid, 0, 0, UP);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int result = solution.uniquePaths(grid);
    cout << "Number of unique paths: " << result << endl;

    vector<vector<int>> grid2 = {{0, 1, 0}, {0, 0, 1}, {0, 0,  0}};
    int result2 = solution.uniquePaths(grid2);
    cout << "Number of unique paths: " << result2 << endl;
    return 0;
}