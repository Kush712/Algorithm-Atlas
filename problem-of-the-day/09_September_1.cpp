// problem 3568 Minimum Moves to Clean the Classroom
// https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    struct State {
            int row;
            int col;
            int energyLeft;
            int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0) 
            return 0;

        VVVVB seen(m, VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        

        queue<State> que;
        que.push({startRow, startCol, maxEnergy, 0});
        seen[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;

        while (!que.empty()) {
            int currSize = que.size();

            while (currSize--) {
                State current = que.front();
                que.pop();

                if (current.collectedMask == allCollected) 
                    return moves;
                if (current.energyLeft == 0) 
                    continue;

                for (auto& dir : directions) {
                    int nextRow = current.row + dir[0];
                    int nextCol = current.col + dir[1];

                    if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n) 
                        continue;

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') 
                        continue;

                    int nextEnergy = current.energyLeft - 1;
                    int nextMask   = current.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    } else if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if (!seen[nextRow][nextCol][nextEnergy][nextMask]) {
                        seen[nextRow][nextCol][nextEnergy][nextMask] = true;
                        que.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<string> classroom = {
        "S..L",
        ".X..",
        "..R.",
        "L..."
    };
    int energy = 3;

    int result = solution.minMoves(classroom, energy);
    cout << "Minimum moves to clean the classroom: " << result << endl;

    vector<string> classroom2 = {
        "S..L",
        ".X..",
        "..R.",
        "L..."
    };
    int energy2 = 1;

    int result2 = solution.minMoves(classroom2, energy2);
    cout << "Minimum moves to clean the classroom: " << result2 << endl;

    return 0;
}   